/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:02:49 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/11 20:51:59 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_start_time(t_data *data)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		data->start_time.time = -1;
		return (-1);
	}
	data->start_time.time = (tv.tv_sec * SEC_MS) + (tv.tv_usec / SEC_MS);
	return (0);
}
