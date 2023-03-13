/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 03:47:44 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/13 03:07:57 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_philos_cycle(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->number_of_philos)
	{
		if (pthread_create(data->philos_threads + i, NULL, philo_thread, data->philos_data + i) == -1)
			return (data->error = 1, -1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	// initial my data and pars the arguments
	if (my_data_init(&data, ac, av) == -1)
		return (printf("Erorr!\n"), EXIT_FAILURE);
	// allocat memory
	if (alloc_needs(data) == -1)
		return (free(data), printf("Erorr!\n"), EXIT_FAILURE);
	// creart mutexs for forks
	if (creat_forks_mutex(data) == -1)
		return (free(data->forks_mutex), free(data->philos_threads), free(data),
			printf("Erorr!\n"), EXIT_FAILURE);
	// allocat and set philos threads arg
	// ....
	// start threads/philos cycle eat->sleep->think..
	if (start_philos_cycle(data) == -1)
		return (free(data->forks_mutex), free(data->philos_threads), free(data),
			printf("Erorr!\n"), EXIT_FAILURE);
	// do the main thread job is to check if a philo die!
	while (1)
	{
		if (data->error)
			return (printf("finished! (Error)\n"), -1);
		usleep(500);
	}
	// join the threads
	// ....
	// free all the data
	// ....
	return (EXIT_SUCCES);
}
