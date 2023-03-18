/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pros.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 02:16:51 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/18 04:31:06 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_forks(t_philo *philo)
{
	if (sem_wait(philo->sem_forks) == -1)
		return (-1);
	if (philo_take_fork(philo) == -1)
		return (-1);
	if (sem_wait(philo->sem_forks) == -1)
		return (-1);
	if (philo_take_fork(philo) == -1)
		return (-1);
	return (0);
}

static int	putback_forks(t_philo *philo)
{
	if (sem_post(philo->sem_forks) == -1)
		return (-1);
	if (sem_post(philo->sem_forks) == -1)
		return (-1);
	return (0);
}

static void	*philo_thread(void *philo)
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
	}
	return (NULL);
}

static int	check_philo(t_data *data)
{
	LL	curr_time;

	if (data->philo_data.he_is == EAT)
		return (0);
	curr_time = calc_curr_time(&(data->philo_data));
	if (curr_time == -1)
		return (clean_two(data), exit(EXIT_ERR), 0);
	if (curr_time - data->philo_data.end_eattime.time >= data->time_to_die)
		return (clean_two(data), exit(EXIT_DIE), 0);
	if (data->philo_data.nums_to_eat == 0)
		return (clean_two(data), exit(EXIT_SUCCES), 0);
	return (0);
}

void	philo_proces(t_data *data)
{
	if (pthread_create(&data->philo_thread, NULL, philo_thread,
			&(data->philo_data)) != 0)
	{
		clean_two(data);
		exit(EXIT_ERR);
	}
	while (1)
	{
		check_philo(data);
		if (data->error == 1)
		{
			clean_two(data);
			exit(EXIT_ERR);
		}
		usleep(20);
	}
}
