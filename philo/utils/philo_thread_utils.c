/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:57:18 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/31 22:41:47 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_err(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_error);
	philo->error = 1;
	pthread_mutex_unlock(&philo->mutex_error);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_he_is);
	philo->he_is = EAT;
	pthread_mutex_unlock(&philo->mutex_he_is);
	pthread_mutex_lock(&philo->mutex_id);
	pthread_mutex_lock(philo->print_mutex);
	printf("%lld %lld is eating\n", get_curr_time() - philo->start_time,
		philo->id + 1);
	pthread_mutex_unlock(philo->print_mutex);
	pthread_mutex_unlock(&philo->mutex_id);
	mysleep(philo->time_to_eat);
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_he_is);
	philo->he_is = SLEEP;
	pthread_mutex_unlock(&philo->mutex_he_is);
	pthread_mutex_lock(&philo->mutex_id);
	pthread_mutex_lock(philo->print_mutex);
	printf("%lld %lld is sleeping\n", get_curr_time() - philo->start_time,
		philo->id + 1);
	pthread_mutex_unlock(philo->print_mutex);
	pthread_mutex_unlock(&philo->mutex_id);
	mysleep(philo->time_to_sleep);
}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_he_is);
	philo->he_is = THINK;
	pthread_mutex_unlock(&philo->mutex_he_is);
	pthread_mutex_lock(&philo->mutex_id);
	pthread_mutex_lock(philo->print_mutex);
	printf("%lld %lld is thinking\n", get_curr_time() - philo->start_time,
		philo->id + 1);
	pthread_mutex_unlock(philo->print_mutex);
	pthread_mutex_unlock(&philo->mutex_id);
}

void	philo_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_he_is);
	philo->he_is = DIE;
	pthread_mutex_unlock(&philo->mutex_he_is);
	pthread_mutex_lock(&philo->mutex_id);
	pthread_mutex_lock(philo->print_mutex);
	printf("%lld %lld died\n", get_curr_time() - philo->start_time, philo->id
		+ 1);
	pthread_mutex_unlock(philo->print_mutex);
	pthread_mutex_unlock(&philo->mutex_id);
}
