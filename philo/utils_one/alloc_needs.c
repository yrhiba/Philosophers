/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_needs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 23:13:47 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/11 23:14:13 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	alloc_needs(t_data *data)
{
	data->philos_threads = (pthread_t *)malloc(sizeof(pthread_t)
			* data->number_of_philos);
	if (!(data->philos_threads))
		return (-1);
	data->forks_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->number_of_philos);
	if (!(data->forks_mutex))
		return (free(data->philos_threads), -1);
	return (0);
}
