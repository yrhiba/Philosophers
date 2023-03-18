/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_semaphore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 00:48:49 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/18 00:57:49 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	open_semaphore(t_data *data)
{
	data->sem_forks = sem_open(SEMFORKS, O_CREAT, 0644, data->number_of_philos);
	if (data->sem_forks == SEM_FAILED)
		return (-1);
	return (0);
}
