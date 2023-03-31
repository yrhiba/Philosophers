/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_needs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:22:04 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/31 07:35:10 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	alloc_needs(t_data *data)
{
	data->threads = (pthread_t *)malloc(sizeof(pthread_t)
			* data->number_of_philos);
	if (!(data->threads))
		return (perror("err::malloc"), -1);
	data->philo_data = (t_philo *)malloc(sizeof(t_philo)
			* data->number_of_philos);
	if (!(data->philo_data))
		return (free(data->threads), perror("err::malloc"), -1);
	data->forks_mutexs = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->number_of_philos);
	if (!(data->forks_mutexs))
		return (free(data->threads), free(data->philo_data),
			perror("err::malloc"), -1);
	return (0);
}
