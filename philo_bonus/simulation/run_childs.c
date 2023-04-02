/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_childs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:38:01 by yrhiba            #+#    #+#             */
/*   Updated: 2023/04/02 08:40:08 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	start_half_one(t_data *data)
{
	LL	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		(data->philos_ids)[i] = fork();
		if ((data->philos_ids)[i] == -1)
			kill(0, SIGINT);
		else if (data->philos_ids[i] == 0)
		{
			data->philo_data.id = i;
			data->id = i;
			philo_proces(data);
		}
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
		(data->philos_ids)[i] = fork();
		if ((data->philos_ids)[i] == -1)
			kill(0, SIGINT);
		else if (data->philos_ids[i] == 0)
		{
			data->philo_data.id = i;
			data->id = i;
			philo_proces(data);
		}
		i += 2;
	}
	return (0);
}

int	run_childs(t_data *data)
{
	if (start_half_one(data) == -1)
		kill(0, SIGINT);
	usleep(300);
	if (start_half_two(data) == -1)
		kill(0, SIGINT);
	return (0);
}
