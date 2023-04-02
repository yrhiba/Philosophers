/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 05:05:59 by yrhiba            #+#    #+#             */
/*   Updated: 2023/04/02 05:08:27 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	mysleep(LL time_ms)
{
	LL	start;

	start = get_curr_time();
	while (get_curr_time() - start < time_ms)
		usleep(700);
}
