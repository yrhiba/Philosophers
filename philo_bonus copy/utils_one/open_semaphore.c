/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_semaphore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:48:49 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/19 03:27:53 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	open_semaphore(t_data *data)
{
	sem_unlink(SEMFORKS);
	data->sem_forks = sem_open(SEMFORKS, O_CREAT, 0666, data->number_of_philos);
	if (data->sem_forks == SEM_FAILED)
		return (-1);
	data->sem_printf = sem_open(SEMPRINT, O_CREAT, 0666, 1);
	if (data->sem_printf == SEM_FAILED)
		return (sem_close(data->sem_forks), sem_unlink(SEMFORKS), -1);
	return (0);
}
