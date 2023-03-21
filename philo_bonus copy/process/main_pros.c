/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pros.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 04:27:16 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/19 02:39:06 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main_proces(t_data *data)
{
	LL	num_of_terminated;

	num_of_terminated = 0;
	while (num_of_terminated < data->number_of_philos)
	{
		if (waitpid(-1, NULL, 0) == -1)
			return (-1);
		num_of_terminated++;
	}
	return (0);
}
