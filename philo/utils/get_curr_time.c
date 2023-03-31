/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_curr_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:58:08 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/31 08:01:01 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

LL	get_curr_time(void)
{
	struct timeval	tv;
	LL				curr_time;

	gettimeofday(&tv, NULL);
	curr_time = (tv.tv_sec * SEC_MS) + (tv.tv_usec / SEC_MS);
	return (curr_time);
}
