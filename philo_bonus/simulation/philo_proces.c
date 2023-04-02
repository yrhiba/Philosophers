/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_proces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 02:46:11 by yrhiba            #+#    #+#             */
/*   Updated: 2023/04/02 08:42:09 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		philo_eat(philo);
		sem_post(philo->sem_forks);
		sem_post(philo->sem_forks);
		sem_wait(philo->sem_sync);
		philo->must_eat -= 1;
		if (philo->must_eat == 0)
			return (sem_post(philo->sem_sync), NULL);
		philo->end_eattime = get_curr_time();
		sem_post(philo->sem_sync);
		philo_sleep(philo);
		sem_wait(philo->sem_print);
		printf("%lld %lld is thinking\n", get_curr_time() - philo->start_time,
			philo->id + 1);
		sem_post(philo->sem_print);
	}
	return (NULL);
}

void	check_die(t_data *data)
{
	t_philo	*philo;

	philo = &data->philo_data;
	while (1)
	{
		sem_wait(philo->sem_sync);
		if (philo->must_eat == 0)
			exit(0);
		if (get_curr_time() - philo->end_eattime >= data->time_to_die)
		{
			sem_wait(data->sem_print);
			printf("%lld %lld die\n", get_curr_time() - data->start_time,
				data->id + 1);
			kill(0, SIGINT);
		}
		sem_post(philo->sem_sync);
		usleep(800);
	}
}

void	philo_proces(t_data *data)
{
	data->philo_data.sem_sync = data->sem_scyns[data->id];
	pthread_create(&data->thread, NULL, philo_routine, &data->philo_data);
	pthread_detach(data->thread);
	check_die(data);
}
