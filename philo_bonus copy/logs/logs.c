/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 04:24:01 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/19 03:34:24 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eat(t_data *data)
{
	t_philo *philo;
	LL	curr_time;

	philo = &data->philo_data;
	curr_time = calc_curr_time(philo);
	if (curr_time == -1)
		return (-1);
	philo->he_is = EAT;
	if (sem_wait(data->sem_printf) == -1)
		kill(0, SIGINT);
	printf("%lld %lld is eating\n", curr_time, philo->id + 1);
	if (sem_post(data->sem_printf) == -1)
		kill(0, SIGINT);
	return (0);
}

int	philo_died(t_data *data)
{
	t_philo *philo;
	LL	curr_time;

	philo = &data->philo_data;
	curr_time = calc_curr_time(philo);
	if (curr_time == -1)
		return (-1);
	philo->he_is = DIE;
	if (sem_wait(data->sem_printf) == -1)
		kill(0, SIGINT);
	printf("%lld %lld died\n", curr_time, philo->id + 1);
	if (sem_post(data->sem_printf) == -1)
		kill(0, SIGINT);
	return (0);
}

int	philo_sleep(t_data *data)
{
	t_philo *philo;
	LL	curr_time;

	philo = &data->philo_data;
	curr_time = calc_curr_time(philo);
	if (curr_time == -1)
		return (-1);
	philo->he_is = SLEEP;
	if (sem_wait(data->sem_printf) == -1)
		kill(0, SIGINT);
	printf("%lld %lld is sleeping\n", curr_time, philo->id + 1);
	if (sem_post(data->sem_printf) == -1)
		kill(0, SIGINT);
	return (0);
}

int	philo_think(t_data *data)
{
	t_philo *philo;
	LL	curr_time;

	philo = &data->philo_data;
	curr_time = calc_curr_time(philo);
	if (curr_time == -1)
		return (-1);
	philo->he_is = THINK;
	if (sem_wait(data->sem_printf) == -1)
		kill(0, SIGINT);
	printf("%lld %lld is thinking\n", curr_time, philo->id + 1);
	if (sem_post(data->sem_printf) == -1)
		kill(0, SIGINT);
	return (0);
}

int	philo_take_fork(t_data *data)
{
	t_philo *philo;
	LL	curr_time;

	philo = &data->philo_data;
	curr_time = calc_curr_time(philo);
	if (curr_time == -1)
		return (-1);
	if (sem_wait(data->sem_printf) == -1)
		kill(0, SIGINT);
	printf("%lld %lld has taken a fork\n", curr_time, philo->id + 1);
	if (sem_post(data->sem_printf) == -1)
		kill(0, SIGINT);
	return (0);
}
