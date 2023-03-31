/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:54:50 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/31 21:40:04 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	set_philo_mutexs(t_philo *philo)
{
	if (pthread_mutex_init(&philo->mutex_id, NULL) == -1)
		return (-1);
	if (pthread_mutex_init(&philo->mutex_error, NULL) == -1)
		return (-1);
	if (pthread_mutex_init(&philo->mutex_he_is, NULL) == -1)
		return (-1);
	if (pthread_mutex_init(&philo->mutex_must_eat, NULL) == -1)
		return (-1);
	if (pthread_mutex_init(&philo->mutex_endtime, NULL) == -1)
		return (-1);
	return (0);
}

static void	set_data(t_data *data, t_philo *philo, int id)
{
	philo->id = id;
	philo->he_is = THINK;
	philo->time_to_sleep = data->time_to_sleep;
	philo->time_to_eat = data->time_to_eat;
	philo->must_eat = data->must_eat;
	philo->start_time = data->start_time;
	philo->end_eat_time = get_curr_time();
	philo->error = 0;
	philo->right_fork = data->forks_mutexs + id;
	if (id == data->number_of_philos - 1)
		philo->left_fork = data->forks_mutexs;
	else
		philo->left_fork = data->forks_mutexs + id + 1;
	philo->print_mutex = &data->print_mutex;
}

int	set_philo_data(t_data *data)
{
	LL	i;

	i = -1;
	data->start_time = get_curr_time();
	while (++i < data->number_of_philos)
	{
		if (set_philo_mutexs(data->philo_data + i) == -1)
			return (-1);
		set_data(data, data->philo_data + i, i);
	}
	return (0);
}
