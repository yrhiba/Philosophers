/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:36:41 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/31 21:58:46 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_half_one(t_data *data)
{
	LL	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		if (pthread_create(data->threads + i, NULL, philo_thread,
				data->philo_data + i) == -1)
			return (-1);
		pthread_detach(data->threads[i]);
		i += 2;
	}
	return (0);
}

static int	start_half_two(t_data *data)
{
	LL	i;

	i = 1;
	while (i < data->number_of_philos)
	{
		if (pthread_create(data->threads + i, NULL, philo_thread,
				data->philo_data + i) == -1)
			return (-1);
		pthread_detach(data->threads[i]);
		i += 2;
	}
	return (0);
}

int	start_threads(t_data *data)
{
	if (start_half_one(data) == -1)
		return (-1);
	usleep(200);
	if (start_half_two(data) == -1)
		return (-1);
	return (0);
}
