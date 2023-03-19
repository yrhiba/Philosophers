/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pros.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 02:16:51 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/19 02:21:39 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*check_die(void *data)
{
	LL	curr_time;

	while (1)
	{
		if (((t_data *)data)->philo_data.he_is == EAT)
			continue ;
		curr_time = get_curr_time();
		if (curr_time
			- ((t_data *)data)->philo_data.end_eattime.time
			>= ((t_data *)data)->time_to_die)
		{
			philo_died(&(((t_data *)data)->philo_data));
			kill(0, SIGINT);
		}
		usleep(20);
	}
	return (NULL);
}

int	philo_proces(t_data *data)
{
	if (pthread_create(&data->check_thread, NULL, check_die, data) != 0)
		return (kill(0, SIGINT), -1);
	while (data->nums_to_eat > 0)
	{
		sem_wait(data->sem_forks);
		philo_take_fork(&data->philo_data);
		sem_wait(data->sem_forks);
		philo_take_fork(&data->philo_data);
		philo_eat(&data->philo_data);
		usleep(data->time_to_eat * 1e3);
		sem_post(data->sem_forks);
		sem_post(data->sem_forks);
		data->nums_to_eat--;
		data->philo_data.end_eattime.time = get_curr_time();
		philo_sleep(&data->philo_data);
		usleep(data->time_to_sleep * 1e3);
		philo_think(&data->philo_data);
	}
	return (exit(EXIT_SUCCES), 0);
}
