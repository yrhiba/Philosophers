/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 04:24:01 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/11 21:03:59 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_philo *philo)
{
	LL	curr_time;

	curr_time = calc_curr_time(philo);
	if (curr_time == -1)
		return (-1);
	printf("%lld %lld is eating\n", curr_time, philo->id);
	return (0);
}

int	philo_died(t_philo *philo)
{
	LL	curr_time;

	curr_time = calc_curr_time(philo);
	if (curr_time == -1)
		return (-1);
	printf("%lld %lld died\n", curr_time, philo->id);
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	LL	curr_time;

	curr_time = calc_curr_time(philo);
	if (curr_time == -1)
		return (-1);
	printf("%lld %lld is sleeping\n", curr_time, philo->id);
	return (0);
}

int	philo_think(t_philo *philo)
{
	LL	curr_time;

	curr_time = calc_curr_time(philo);
	if (curr_time == -1)
		return (-1);
	printf("%lld %lld is thinking\n", curr_time, philo->id);
	return (0);
}

int	philo_take_fork(t_philo *philo)
{
	LL	curr_time;

	curr_time = calc_curr_time(philo);
	if (curr_time == -1)
		return (-1);
	printf("%lld %lld has taken a fork\n", curr_time, philo->id);
	return (0);
}
