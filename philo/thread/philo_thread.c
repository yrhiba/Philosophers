/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:48:40 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/14 23:05:37 by yrhiba           ###   ########.fr       */
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

void	*philo_thread(void *philo)
{
	while (((t_philo *)philo)->nums_to_eat > 0)
	{
		if (take_forks(((t_philo *)philo)) != 0)
			return (*(((t_philo *)philo)->error) = 1, NULL);
		if (philo_eat(((t_philo *)philo)) == -1)
			return (*(((t_philo *)philo)->error) = 1, NULL);
		usleep((*(((t_philo *)philo)->time_to_eat))*1e3);
		((t_philo *)philo)->nums_to_eat -= 1;
		if (putback_forks(((t_philo *)philo)) != 0)
			return (*(((t_philo *)philo)->error) = 1, NULL);
		if (((t_philo *)philo)->nums_to_eat == 0)
			return (NULL);
		if (philo_sleep(((t_philo *)philo)) == -1)
			return (*(((t_philo *)philo)->error) = 1, NULL);
		usleep((*(((t_philo *)philo)->time_to_sleep))*1e3);
		if (philo_think(((t_philo *)philo)) == -1)
			return (*(((t_philo *)philo)->error) = 1, NULL);
		if (*(((t_philo *)philo)->error))
			return (NULL);
	}
	return (NULL);
}
