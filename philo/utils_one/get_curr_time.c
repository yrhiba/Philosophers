/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curr_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:49:57 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/11 20:52:12 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

LL	get_curr_time(void)
{
	struct timeval	tv;
	LL				curr_time;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	curr_time = (tv.tv_sec * SEC_MS) + (tv.tv_usec / SEC_MS);
	return (curr_time);
}
