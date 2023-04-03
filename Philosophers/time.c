/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 08:46:05 by mincshin          #+#    #+#             */
/*   Updated: 2023/03/25 14:58:48 by mincshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	start_count(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	time_spent(t_data *data, int action)
{
	unsigned long	begin;

	begin = start_count();
	while (data->died == 0)
	{
		if (start_count() - begin >= (unsigned long) action)
			break ;
		usleep(200);
	}
}

void	check_health(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (1 && data->nbphilo != 1)
	{
		pthread_mutex_lock(&(data->ate));
		if (data->philos_ate == data->nbphilo)
		{
			pthread_mutex_unlock(&(data->ate));
			break ;
		}
		if (start_count() - philo[i].last_meal >= (unsigned long) data->ttdie)
		{
			pthread_mutex_lock(&(data->writing));
			data->died = 1;
			printf("%lu %d died\n", start_count() - \
				data->time, philo[i].id);
			pthread_mutex_unlock(&(data->ate));
			pthread_mutex_unlock(&(data->writing));
			break ;
		}
		i = (i + 1) % data->nbphilo;
		pthread_mutex_unlock(&(data->ate));
		usleep(500);
	}
}
