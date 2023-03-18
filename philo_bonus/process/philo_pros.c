/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pros.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 02:16:51 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/18 12:03:07 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_forks(t_philo *philo)
{
	if (sem_wait(*(philo->sem_forks)) == -1)
		return (-1);
	if (philo_take_fork(philo) == -1)
		return (-1);
	if (sem_wait(*(philo->sem_forks)) == -1)
		return (-1);
	if (philo_take_fork(philo) == -1)
		return (-1);
	return (0);
}

static int	putback_forks(t_philo *philo)
{
	if (sem_post(*(philo->sem_forks)) == -1)
		return (-1);
	if (sem_post(*(philo->sem_forks)) == -1)
		return (-1);
	return (0);
}

static void	*philo_thread(void *philo)
{
	while (((t_philo *)philo)->nums_to_eat > 0)
	{
		if (take_forks(((t_philo *)philo)) != 0)
			return (printf("Erorr!\n"), kill(0, SIGINT), NULL);
		if (philo_eat(((t_philo *)philo)) == -1)
			return (printf("Erorr!\n"), kill(0, SIGINT), NULL);
		usleep((*(((t_philo *)philo)->time_to_eat)) * 1e3);
		((t_philo *)philo)->nums_to_eat -= 1;
		if (putback_forks(((t_philo *)philo)) != 0)
			return (printf("Erorr!\n"), kill(0, SIGINT), NULL);
		if (((t_philo *)philo)->nums_to_eat == 0)
			return (NULL);
		if (philo_sleep(((t_philo *)philo)) == -1)
			return (printf("Erorr!\n"), kill(0, SIGINT), NULL);
		usleep((*(((t_philo *)philo)->time_to_sleep)) * 1e3);
		if (philo_think(((t_philo *)philo)) == -1)
			return (printf("Erorr!\n"), kill(0, SIGINT), NULL);
	}
	return (NULL);
}

static void	*check_philo(void *data)
{
	LL	curr_time;

	while (1)
	{
		if (((t_data *)data)->philo_data.he_is == EAT)
			continue;
		curr_time = calc_curr_time(&(((t_data *)data)->philo_data));
		if (curr_time == -1)
			return (printf("exit philo error!\n"), clean_two(data), kill(0, SIGINT), NULL);
		if (curr_time - (((t_data *)data)->philo_data).end_eattime.time >= ((t_data *)data)->time_to_die)
			return (printf("->exit philo die!\n"), clean_two(data), kill(0, SIGINT), NULL);
		if (((t_data *)data)->philo_data.nums_to_eat == 0)
			return (printf("exit philo finish eating!\n"), clean_two(((t_data *)data)), exit(EXIT_SUCCES), NULL);
		if (((t_data *)data)->error == 1)
		{
			clean_two(((t_data *)data));
			printf("exit data error !\n");
			kill(0, SIGINT);
		}
		usleep(20);
	}
	return (NULL);
}

void	philo_proces(t_data *data)
{
	if (pthread_create(&data->philo_thread, NULL, check_philo,
			data) != 0)
	{
		clean_two(data);
		printf("exit error pthread creat !\n");
		kill(0, SIGINT);
	}
	philo_thread(&data->philo_data);
}
