/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos_cycle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:09:07 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/19 02:50:53 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_half_one(t_data *data)
{
	LL	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		if (pthread_create(data->philos_threads + i, NULL, philo_thread,
				data->philos_data + i) == -1)
			return (data->error = 1, -1);
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
		if (pthread_create(data->philos_threads + i, NULL, philo_thread,
				data->philos_data + i) == -1)
			return (data->error = 1, -1);
		i += 2;
	}
	return (0);
}

int	start_philos_cycle(t_data *data)
{
	if (start_half_one(data) == -1)
		return (-1);
	usleep(50);
	if (start_half_two(data) == -1)
		return (-1);
	return (0);
}
