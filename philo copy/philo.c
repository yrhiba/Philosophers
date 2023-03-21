/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 03:47:44 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/20 15:43:37 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_data(t_data *data)
{
	int	j;

	j = 0;
	while (j < data->number_of_philos)
	{
		pthread_mutex_destroy(&(((t_philo *)(data->philos_data + j))->mutex_error));
		pthread_mutex_destroy(&(((t_philo *)(data->philos_data + j))->mutex_endtime));
		pthread_mutex_destroy(&(((t_philo *)(data->philos_data + j))->mutex_nums_to_eat));
		j++;
	}
	destroy_mutexs(data, (int)data->number_of_philos);
	free(data->philos_threads);
	free(data->forks_mutex);
	free(data->philos_data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (my_data_init(&data, ac, av) == -1)
		return (printf("Erorr!\n"), EXIT_FAILURE);
	if (alloc_needs(data) == -1)
		return (free(data), printf("Erorr!\n"), EXIT_FAILURE);
	if (creat_forks_mutex(data) == -1)
		return (free(data->forks_mutex), free(data->philos_threads), free(data),
			printf("Erorr!\n"), EXIT_FAILURE);
	if (allocat_philos_data(data) == -1)
		return (free(data->forks_mutex), free(data->philos_threads), free(data),
			printf("Erorr!\n"), EXIT_FAILURE);
	if (start_philos_cycle(data) == -1)
		return (free_data(data), printf("error!\n"), -1);
	if (main_thread(data) == -1)
		return (free_data(data), printf("error!\n"), -1);
	return (free_data(data), EXIT_SUCCES);
}
