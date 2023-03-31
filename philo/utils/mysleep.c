/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 08:54:00 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/31 22:32:11 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mysleep(LL time_ms)
{
	LL	start;

	start = get_curr_time();
	while (get_curr_time() - start < time_ms)
		usleep(700);
}
