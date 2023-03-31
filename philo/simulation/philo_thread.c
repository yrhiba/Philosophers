/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:40:38 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/31 22:16:28 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(&philo->mutex_id);
	pthread_mutex_lock(philo->print_mutex);
	printf("%lld %lld has taken a fork\n", get_curr_time() - philo->start_time,
		philo->id + 1);
	pthread_mutex_unlock(philo->print_mutex);
	pthread_mutex_unlock(&philo->mutex_id);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->mutex_id);
	pthread_mutex_lock(philo->print_mutex);
	printf("%lld %lld has taken a fork\n", get_curr_time() - philo->start_time,
		philo->id + 1);
	pthread_mutex_unlock(philo->print_mutex);
	pthread_mutex_unlock(&philo->mutex_id);
}

static int	putback_forks(t_philo *philo)
{
	int	a;

	a = 0;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_lock(&philo->mutex_must_eat);
	philo->must_eat -= 1;
	if (philo->must_eat == 0)
		a = 1;
	pthread_mutex_unlock(&philo->mutex_must_eat);
	return (a);
}

void	*philo_thread(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		take_forks(philo);
		pthread_mutex_lock(&philo->mutex_endtime);
		philo->end_eat_time = get_curr_time();
		pthread_mutex_unlock(&philo->mutex_endtime);
		philo_eat(philo);
		if (putback_forks(philo) == 1)
			return (NULL);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
