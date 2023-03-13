/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos_cycle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:09:07 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/13 19:32:56 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	exit_error(t_data *data, int ithr)
{
	int	i;

	i = 0;
	while (i < ithr)
	{
		pthread_join(data->philos_threads[i], NULL);
		i++;
	}
}

int	start_philos_cycle(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		if (pthread_create(data->philos_threads + i, NULL, philo_thread,
				data->philos_data + i) == -1)
			return (data->error = 1, exit_error(data, i), -1);
		i++;
	}
	return (0);
}
