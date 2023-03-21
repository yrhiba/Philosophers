/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos_cycle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 01:01:25 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/19 02:38:07 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	kill_created_pros(t_data *data)
{
	LL	i;

	i = -1;
	while (++i < data->number_of_philos)
		kill(data->philos_ids[i], SIGINT);
}

static int	start_half_one(t_data *data)
{
	LL	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		(data->philos_ids)[i] = fork();
		if ((data->philos_ids)[i] == -1)
			return (kill_created_pros(data), -1);
		else if (data->philos_ids[i] == 0)
		{
			data->philo_data.id = i;
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
			return (kill_created_pros(data), -1);
		else if (data->philos_ids[i] == 0)
		{
			data->philo_data.id = i;
			philo_proces(data);
		}
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
