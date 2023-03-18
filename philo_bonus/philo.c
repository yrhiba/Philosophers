/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:12:57 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/18 04:30:36 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_one(t_data *data)
{
	sem_close(data->sem_forks);
	sem_unlink(SEMFORKS);
	free(data->philos_ids);
	free(data);
}

void	clean_two(t_data *data)
{
	sem_close(data->sem_forks);
	free(data->philos_ids);
	free(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (my_data_init(&data, ac, av) == -1)
		return (printf("Erorr!\n"), EXIT_FAILURE);
	if (alloc_needs(data) == -1)
		return (free(data), printf("Erorr!\n"), EXIT_FAILURE);
	if (start_philos_cycle(data) == -1)
		return (clean_one(data), printf("Erorr!\n"), EXIT_FAILURE);
	if (main_proces(data) == -1)
		return (clean_two(data), printf("Erorr!\n"), EXIT_FAILURE);
	return (clean_one(data), 0);
}
