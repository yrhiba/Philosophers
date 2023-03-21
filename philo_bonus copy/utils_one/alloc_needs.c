/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_needs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 23:25:49 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/18 10:56:59 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	alloc_needs(t_data *data)
{
	data->philos_ids = (pid_t *)malloc(sizeof(pid_t) * data->number_of_philos);
	if (!data->philos_ids)
		return (-1);
	return (0);
}
