/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:48:40 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/13 03:10:44 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_thread(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		philo_eat(philo);
		usleep(SEC_US);
		philo_sleep(philo);
		usleep(SEC_US);
		philo_think(philo);
		usleep(SEC_US);
		if (*(philo->error))
			return (-1);
	}
	return (free(philo), NULL);
}
