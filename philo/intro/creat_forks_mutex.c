/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_forks_mutex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:38:11 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/31 21:39:09 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexs(t_data *data, LL size)
{
	LL	j;

	j = -1;
	while (++j < size)
		pthread_mutex_destroy(data->forks_mutexs + j);
}

int	creat_forks_mutex(t_data *data)
{
	LL	i;

	i = -1;
	while (++i < data->number_of_philos)
		pthread_mutex_init(data->forks_mutexs + i, NULL);
	pthread_mutex_init(&data->print_mutex, NULL);
	return (0);
}
