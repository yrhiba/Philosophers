/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocat_philos_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:31:39 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/14 05:06:29 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_philo_data(t_data *data, t_philo *philo, int id)
{
	philo->id = id;
	philo->he_is = THINK;
	philo->time_to_sleep = &(data->time_to_sleep);
	philo->time_to_eat = &(data->time_to_eat);
	philo->nums_to_eat = data->nums_to_eat;
	philo->start_time = &(data->start_time);
	philo->end_eattime.time = 0;
	philo->error = &(data->error);
	philo->finish = &(data->finish);
	philo->right_fork = data->forks_mutex + id;
	if (id == data->number_of_philos - 1)
		philo->left_fork = data->forks_mutex;
	else
		philo->left_fork = data->forks_mutex + id + 1;
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
		set_philo_data(data, data->philos_data + i, i);
	return (0);
}
