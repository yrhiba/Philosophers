/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_curr_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:59:00 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/20 15:44:25 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

LL	calc_curr_time(t_philo *philo)
{
	LL	curr_time;

	curr_time = get_curr_time();
	if (curr_time == -1)
		return (-1);
	return (curr_time - ((philo->start_time)).time);
}
