/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 03:47:44 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/11 23:15:23 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	start_philos_cycle(t_data *data)
// {
// 	t_philo	*arg;
// 	int		i;

// 	i = 0;
// 	while (i < data->number_of_philos)
// 	{
// 		/*
// 			creat data arg for thread
// 			creat threads
// 			join the thread
// 		*/
// 		arg = (t_philo *)malloc(sizeof(t_philo));
// 		if (!arg)
// 			return (data->error = 1, -1);
// 		arg->id = i;
// 		if (pthread_create(data->philos_threads + i, NULL, philo_thread, arg) == -1)
// 			return (data->error = 1, -1);
// 		i++;
// 	}
// 	return (0);
// }

int	main(int ac, char **av)
{
	t_data	*data;

	if (my_data_init(&data, ac, av) == -1)
		return (printf("Erorr!\n"), EXIT_FAILURE);
	if (alloc_needs(data) == -1)
		return (free(data), printf("Erorr!\n"), EXIT_FAILURE);
	if (creat_forks_mutex(data) == -1)
		return (free(data), printf("Erorr!\n"), EXIT_FAILURE);
	// if (start_philos_cycle(data) == -1)
	// 	return (free(data), printf("Erorr!\n"), EXIT_FAILURE);
	return (EXIT_SUCCES);
}
