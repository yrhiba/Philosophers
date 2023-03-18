/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_semaphore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:48:49 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/18 08:59:56 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	open_semaphore(t_data *data)
{
	LL	i;

	data->sem_forks = sem_open(SEMFORKS, O_CREAT, 0644, 0);
	if (data->sem_forks == SEM_FAILED)
		return (-1);
	i = -1;
	while (++i < data->number_of_philos)
	{
		if (sem_post(data->sem_forks) == -1)
			return (sem_close(data->sem_forks), sem_unlink(SEMFORKS), -1);
	}
	return (0);
}
