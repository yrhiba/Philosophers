/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocat_philos_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:31:39 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/20 16:22:42 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_philo_data(t_data *data, t_philo *philo, int id)
{
	philo->id = id;
	philo->he_is = THINK;
	philo->time_to_sleep = data->time_to_sleep;
	philo->time_to_eat = data->time_to_eat;
	philo->nums_to_eat = data->nums_to_eat;
	philo->start_time.time = data->start_time.time;
	philo->end_eattime.time = 0;
	philo->error = 0;
	philo->finish = 0;
	philo->right_fork = data->forks_mutex + id;
	if (id == data->number_of_philos - 1)
		philo->left_fork = data->forks_mutex;
	else
		philo->left_fork = data->forks_mutex + id + 1;
}


static	int	init_mutex(t_philo *philo)
{
	if (pthread_mutex_init(&philo->mutex_error, NULL) == -1)
		return (-1);
	if (pthread_mutex_init(&philo->mutex_nums_to_eat, NULL) == -1)
		return (pthread_mutex_destroy(&philo->mutex_error), -1);
	if (pthread_mutex_init(&philo->mutex_endtime, NULL) == -1)
	{
		pthread_mutex_destroy(&philo->mutex_nums_to_eat);
		return (pthread_mutex_destroy(&philo->mutex_error), -1);
	}
	return (0);
}

int	allocat_philos_data(t_data *data)
{
	LL	i;

	data->philos_data = (t_philo *)malloc(sizeof(t_philo)
			* data->number_of_philos);
	if (!(data->philos_data))
		return (-1);
	i = -1;
	while (++i < data->number_of_philos)
	{
		set_philo_data(data, data->philos_data + i, i);
		if (init_mutex(data->philos_data + i) == -1)
			return (free(data->philos_data), -1);
	}
	return (0);
}
