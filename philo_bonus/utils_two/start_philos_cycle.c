/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philos_cycle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 01:01:25 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/18 01:11:57 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	kill_created_pros(t_data *data, LL count)
{
	LL	i;

	i = 0;
	while (i < count)
		kill(data->philos_ids[i++], SIGTERM);
}

int	start_philos_cycle(t_data *data)
{
	LL	i;

	i = -1;
	while (++i < data->number_of_philos)
	{
		(data->philos_ids)[i] = fork();
		if ((data->philos_ids)[i] == -1)
			return (kill_created_pros(data, i), -1);
		else if ((data->philos_ids[i] == 0))
		{
			data->philo_data.id = i;
			// call the philo function proces
			break;
		}
	}
	return (0);
}