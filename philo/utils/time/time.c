/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 04:55:17 by yrhiba            #+#    #+#             */
/*   Updated: 2023/02/06 11:50:04 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_start_time(t_time *time)
{
	struct timeval	tmp;

	if (gettimeofday(&tmp, NULL) == -1)
		return (perror("error"), exit(EXIT_ERR), -1);
	time->start = (tmp.tv_sec * 1000 + tmp.tv_usec / 1000);
	return (0);
}

ll	get_curr_time(t_time *time)
{
	struct timeval	tmp;

	if (gettimeofday(&tmp, NULL) == -1)
		return (perror("error"), exit(EXIT_ERR), -1);
	return ((tmp.tv_sec * 1000 + tmp.tv_usec / 1000) - time->start);
	return (0);
}
