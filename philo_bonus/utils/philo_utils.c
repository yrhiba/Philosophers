/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 04:59:40 by yrhiba            #+#    #+#             */
/*   Updated: 2023/04/02 05:54:45 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_eat(t_philo *philo)
{
	sem_wait(philo->sem_forks);

	sem_wait(philo->sem_print);
	printf("%lld %lld has taken a fork\n", get_curr_time() - philo->start_time,
			philo->id);
	sem_post(philo->sem_print);

	sem_wait(philo->sem_forks);

	sem_wait(philo->sem_print);
	printf("%lld %lld has taken a fork\n%lld %lld is eating\n", get_curr_time()
			- philo->start_time, philo->id, get_curr_time() - philo->start_time,
			philo->id);
	sem_post(philo->sem_print);

	mysleep(philo->time_to_eat);
}

void	philo_sleep(t_philo *philo)
{
	sem_wait(philo->sem_print);
	printf("%lld %lld is sleeping\n", get_curr_time() - philo->start_time,
			philo->id);
	sem_post(philo->sem_print);

	mysleep(philo->time_to_sleep);
}
