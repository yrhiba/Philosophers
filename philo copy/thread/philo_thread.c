/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:48:40 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/20 17:08:14 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_forks(t_philo *philo)
{
	if (pthread_mutex_lock(philo->right_fork) != 0)
		return (-1);
	if (philo_take_fork(philo) == -1)
		return (-1);
	if (pthread_mutex_lock(philo->left_fork) != 0)
		return (-1);
	if (philo_take_fork(philo) == -1)
		return (-1);
	return (0);
}

static int	putback_forks(t_philo *philo)
{
	if (pthread_mutex_unlock(philo->left_fork) != 0)
		return (-1);
	if (pthread_mutex_unlock(philo->right_fork) != 0)
		return (-1);
	return (0);
}

static int	philo_routine(t_philo *philo)
{
	if (take_forks(philo) != 0)
		return (-1);
	if (philo_eat(philo) == -1)
		return (-1);
	usleep(philo->time_to_eat * 1e3);
	if (putback_forks(philo) != 0)
		return (-1);
	pthread_mutex_lock(&philo->mutex_nums_to_eat);
	philo->nums_to_eat -= 1;
	if (philo->nums_to_eat == 0)
	{
		pthread_mutex_unlock(&philo->mutex_nums_to_eat);
		return (2);
	}
	pthread_mutex_unlock(&philo->mutex_nums_to_eat);
	if (philo_sleep((philo)) == -1)
		return (-1);
	usleep(philo->time_to_sleep * 1e3);
	if (philo_think(philo) == -1)
		return (-1);
	return (0);
}

void	*philo_thread(void *philo)
{
	int	r;

	while (1)
	{
		r = philo_routine((t_philo *)philo);
		if (r == -1)
		{
			pthread_mutex_lock(&((t_philo *)(philo))->mutex_error);
			((t_philo *)(philo))->error = 1;
			pthread_mutex_unlock(&((t_philo *)(philo))->mutex_error);
			return (NULL);
		}
		else if (r == 2)
			return (NULL);
	}
	return (NULL);
}
