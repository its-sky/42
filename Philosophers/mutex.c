/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:57:37 by mincshin          #+#    #+#             */
/*   Updated: 2023/03/25 14:58:10 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbphilo);
	i = -1;
	while (++i < data->nbphilo)
		pthread_mutex_init(&(data->forks[i]), NULL);
	pthread_mutex_init(&(data->writing), NULL);
	pthread_mutex_init(&(data->ate), NULL);
}

void	dstr_mutex_free_data(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbphilo)
		pthread_mutex_destroy(&(data->forks[i]));
	pthread_mutex_destroy(&(data->writing));
	pthread_mutex_destroy(&(data->ate));
	free(data->philo);
	free(data->forks);
}

void	print_msg(char *str, t_data *data, int id)
{
	pthread_mutex_lock(&(data->writing));
	if (!data->died)
		printf("%lu %d %s\n", start_count() - data->time, id, str);
	pthread_mutex_unlock(&(data->writing));
}

void	eating(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (pthread_mutex_lock(&(data->forks[philo->fork_l])) == 0)
		print_msg("has taken a fork", data, philo->id);
	if (pthread_mutex_lock(&(data->forks[philo->fork_r])) == 0)
		print_msg("has taken a fork", data, philo->id);
	print_msg("is eating", data, philo->id);
	philo->last_meal = start_count();
	time_spent(data, data->tteat);
	philo->meals++;
	if (philo->meals == data->nbmeals)
		data->philos_ate++;
	pthread_mutex_unlock(&data->forks[philo->fork_l]);
	pthread_mutex_unlock(&data->forks[philo->fork_r]);
	print_msg("is sleeping", data, philo->id);
	time_spent(data, data->ttsleep);
	print_msg("is thinking", data, philo->id);
}
