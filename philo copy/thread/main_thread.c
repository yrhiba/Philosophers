/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:28:08 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/20 17:08:08 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_die_of_philo(t_philo *philo, t_data *data)
{
	LL	curr_time;

	pthread_mutex_lock(&philo->mutex_error);
	if (philo->error)
		return (-1);
	pthread_mutex_unlock(&philo->mutex_error);
	pthread_mutex_lock(&philo->mutex_nums_to_eat);
	if (philo->nums_to_eat == 0)
		return (pthread_mutex_unlock(&philo->mutex_nums_to_eat), 3);
	pthread_mutex_unlock(&philo->mutex_nums_to_eat);
	curr_time = calc_curr_time(philo);
	if (curr_time == -1)
		return (-1);
	pthread_mutex_lock(&philo->mutex_endtime);
	if (curr_time - philo->end_eattime.time >= data->time_to_die)
		return (1);
	pthread_mutex_unlock(&philo->mutex_endtime);
	return (0);
}

int	main_thread(t_data *data)
{
	int	i;
	int	r;
	int	a;

	while (1)
	{
		a = 0;
		i = -1;
		while (++i < data->number_of_philos)
		{
			r = check_die_of_philo(data->philos_data + i, data);
			if (r == -1)
				return (-1);
			else if (r == 1)
				return (philo_died(data->philos_data + i), 0);
			else if (r == 3)
				a++;
		}
		if (a == data->number_of_philos)
			return (0);
		usleep(100);
	}
	return (0);
}
