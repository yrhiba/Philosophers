/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:40:54 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/31 21:49:38 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philo(t_data *data, LL id)
{
	t_philo	*philo;

	philo = (t_philo *)(data->philo_data + id);
	pthread_mutex_lock(&philo->mutex_must_eat);
	if (philo->must_eat == 0)
		return (pthread_mutex_unlock(&philo->mutex_must_eat), 2);
	pthread_mutex_unlock(&philo->mutex_must_eat);
	pthread_mutex_lock(&philo->mutex_endtime);
	if (get_curr_time() - philo->end_eat_time >= data->time_to_die)
		return (1);
	pthread_mutex_unlock(&philo->mutex_endtime);
	return (0);
}

int	main_thread(t_data *data)
{
	LL	i;
	LL	r;
	LL	a;

	a = -1;
	while (a != data->number_of_philos)
	{
		a = 0;
		i = -1;
		while (++i < data->number_of_philos)
		{
			r = check_philo(data, i);
			if (r == 1)
			{
				pthread_mutex_lock(&data->print_mutex);
				return (printf("%lld %lld died\n", get_curr_time()
						- data->start_time, i + 1), 0);
			}
			if (r == 2)
				a++;
		}
		usleep(500);
	}
	return (0);
}
