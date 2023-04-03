/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:58:34 by mincshin          #+#    #+#             */
/*   Updated: 2023/03/25 14:58:22 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	attr_philo(t_data *data)
{
	int	i;

	data->philo = malloc(sizeof(t_philo) * data->nbphilo);
	data->died = 0;
	i = -1;
	while (++i < data->nbphilo)
	{
		data->philo[i].data = data;
		data->philo[i].id = i + 1;
		data->philo[i].fork_l = i;
		data->philo[i].fork_r = (i + 1) % data->nbphilo;
		data->philo[i].meals = 0;
	}
	init_thread(data);
}

void	init_thread(t_data *data)
{
	t_philo	*philo;
	int		i;

	philo = data->philo;
	data->time = start_count();
	i = -1;
	while (++i < data->nbphilo)
	{
		pthread_create(&data->philo[i].threads, NULL, &routine, \
			&philo[i]);
		pthread_mutex_lock(&(data->ate));
		philo[i].last_meal = start_count();
		pthread_mutex_unlock(&(data->ate));
	}
	i = -1;
	check_health(data, philo);
	while (++i < data->nbphilo)
		pthread_join(philo[i].threads, NULL);
}

int	one_philo(t_data *data)
{
	t_philo	*philo;

	philo = data->philo;
	if (data->nbphilo == 1)
	{
		if (pthread_mutex_lock(&(data->forks[0])) == 0)
			print_msg("has taken a fork", data, philo->id);
		pthread_mutex_unlock(&(data->forks[0]));
		pthread_mutex_lock(&(data->writing));
		usleep(data->ttdie * 1000);
		data->died = 1;
		printf("%lu %d died\n", start_count() - \
			data->time, philo[0].id);
		pthread_mutex_unlock(&(data->ate));
		pthread_mutex_unlock(&(data->writing));
		return (-1);
	}
	return (0);
}

void	*routine(void *p)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)p;
	data = philo->data;
	if (one_philo(data) != 0)
		return (NULL);
	if (philo->id % 2 != 0)
		usleep(15000);
	while (1)
	{	
		pthread_mutex_lock(&(data->ate));
		pthread_mutex_lock(&(data->writing));
		if (data->philos_ate == data->nbphilo || data->died == 1)
		{
			pthread_mutex_unlock(&(data->ate));
			pthread_mutex_unlock(&(data->writing));
			break ;
		}
		pthread_mutex_unlock(&(data->ate));
		pthread_mutex_unlock(&(data->writing));
		eating(philo);
	}
	return (NULL);
}
