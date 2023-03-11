/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 03:47:44 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/11 20:31:48 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (my_data_init(&data, ac, av) == -1)
		return (printf("Erorr!\n"), EXIT_FAILURE);
	return (EXIT_SUCCES);
}

/*
	printf("Start Time -> %lld (ms) | %lld (s)\n", data->start_time.time,
			data->start_time.time / 1000);
	printf("NUmber Of Philos %lld\n", data->number_of_philos);
	printf("Time To Die      %lld\n", data->time_to_die);
	printf("Time To Eat      %lld\n", data->time_to_eat);
	printf("Time To Sleep    %lld\n", data->time_to_sleep);
	printf("Must EAT         %lld\n", data->nums_to_eat);
*/