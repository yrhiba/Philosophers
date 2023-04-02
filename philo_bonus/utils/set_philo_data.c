/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 09:34:04 by yrhiba            #+#    #+#             */
/*   Updated: 2023/04/02 08:41:23 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_philo_data(t_data *data)
{
	t_philo	*philo;

	philo = &data->philo_data;
	philo->id = 0;
	philo->time_to_eat = data->time_to_eat;
	philo->time_to_sleep = data->time_to_sleep;
	philo->must_eat = data->must_eat;
	philo->sem_forks = data->sem_forks;
	philo->sem_print = data->sem_print;
	data->start_time = get_curr_time();
	philo->start_time = data->start_time;
	philo->end_eattime = data->start_time;
}
