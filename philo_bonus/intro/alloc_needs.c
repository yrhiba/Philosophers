/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_needs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:25:34 by yrhiba            #+#    #+#             */
/*   Updated: 2023/04/02 08:29:25 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	open_sem_syncs(t_data *data)
{
	LL	i;

	i = -1;
	while (++i < data->number_of_philos)
	{
		data->semsync_name = lltoch(i);
		sem_unlink(data->semsync_name);
		data->sem_scyns[i] = sem_open(data->semsync_name, O_CREAT, 0666, 1);
		free(data->semsync_name);
	}
	return (0);
}

int	alloc_needs(t_data *data)
{
	sem_unlink(SEMFORKS);
	sem_unlink(SEMPRINT);
	data->philos_ids = (pid_t *)malloc(sizeof(pid_t) * data->number_of_philos);
	if (!data->philos_ids)
		return (perror("err::malloc"), -1);
	data->sem_scyns = (sem_t **)malloc(sizeof(sem_t *)
			* data->number_of_philos);
	if (!data->sem_scyns)
		return (free(data->philos_ids), perror("err::malloc"), -1);
	data->sem_forks = sem_open(SEMFORKS, O_CREAT, 0666, data->number_of_philos);
	if (data->sem_forks == SEM_FAILED)
		return (free(data->philos_ids), free(data->sem_scyns),
			perror("err::sem_open"), -1);
	data->sem_print = sem_open(SEMPRINT, O_CREAT, 0666, 1);
	if (data->sem_print == SEM_FAILED)
		return (free(data->philos_ids), free(data->sem_scyns),
			sem_close(data->sem_forks), sem_unlink(SEMFORKS),
			perror("err::sem_open"), -1);
	if (open_sem_syncs(data) == -1)
		return (free(data->philos_ids), free(data->sem_scyns),
			sem_close(data->sem_forks), sem_unlink(SEMFORKS),
			sem_close(data->sem_print), sem_unlink(SEMPRINT),
			perror("err::sem_open"), -1);
	return (0);
}
