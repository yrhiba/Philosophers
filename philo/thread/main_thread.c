/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:28:08 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/14 05:10:27 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_die_of_philo(t_philo *philo, t_data *data)
{
	LL	curr_time;

	if (philo->end_eattime.time == -1 || philo->he_is == EAT)
		return (0);
	curr_time = calc_curr_time(philo);
	if (curr_time == -1)
		return (-1);
	if (curr_time - philo->end_eattime.time >= data->time_to_die)
		return (1);
	return (0);
}

int	main_thread(t_data *data)
{
	int	i;
	int	r;

	while (!(data->finish))
	{
		i = 0;
		while (i < data->number_of_philos)
		{
			r = check_die_of_philo(data->philos_data + i, data);
			if (r == -1)
				return (data->error = 1, -1);
			else if (r == 1)
				return (philo_died(data->philos_data + i), data->finish = 1, 0);
			i++;
		}
		if (data->error)
			return (-1);
		usleep(100);
	}
	return (0);
}
