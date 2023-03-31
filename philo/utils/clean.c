/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:47:05 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/31 22:41:29 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_philo_mutexs(t_data *data)
{
	LL	i;

	i = -1;
	while (++i < data->number_of_philos)
	{
		pthread_mutex_destroy(&((t_philo *)(data->philo_data
					+ i))->mutex_error);
		pthread_mutex_destroy(&((t_philo *)(data->philo_data
					+ i))->mutex_he_is);
		pthread_mutex_destroy(&((t_philo *)(data->philo_data + i))->mutex_id);
		pthread_mutex_destroy(&((t_philo *)(data->philo_data
					+ i))->mutex_must_eat);
	}
}

int	clean(t_data *data)
{
	pthread_mutex_destroy(&data->print_mutex);
	destroy_mutexs(data, data->number_of_philos);
	destroy_philo_mutexs(data);
	free(data->philo_data);
	free(data->threads);
	free(data->forks_mutexs);
	free(data);
	return (0);
}
