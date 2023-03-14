/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_forks_mutex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 23:02:48 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/14 04:57:37 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexs(t_data *data, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		pthread_mutex_destroy(data->forks_mutex + j);
		j++;
	}
}

int	creat_forks_mutex(t_data *data)
{
	LL	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		if (pthread_mutex_init(data->forks_mutex + i, NULL) == -1)
			return (destroy_mutexs(data, i), data->error = 1, -1);
		i++;
	}
	return (0);
}
