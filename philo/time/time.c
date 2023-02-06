/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 04:55:17 by yrhiba            #+#    #+#             */
/*   Updated: 2023/02/06 05:21:33 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_start_time(t_time *time)
{
	struct timeval	tmp;

	if (gettimeofday(&tmp, NULL) == -1)
		return (-1);
	time->start = (tmp.tv_sec * 1000 + tmp.tv_usec / 1000);
	return (0);
}

int	set_curr_time(t_time *time)
{
	struct timeval	tmp;

	if (gettimeofday(&tmp, NULL) == -1)
		return (-1);
	time->curr = (tmp.tv_sec * 1000 + tmp.tv_usec / 1000);
	return (0);
}
