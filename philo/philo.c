/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 06:04:22 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/31 22:01:54 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	intro(t_data **data, int ac, char **av)
{
	if (my_data_init(data, ac, av) == -1)
		return (-1);
	if (alloc_needs(*data) == -1)
		return (free(*data), -1);
	if (creat_forks_mutex(*data) == -1)
		return (free((*data)->philo_data), free((*data)->threads),
			free((*data)->forks_mutexs), free(*data), -1);
	if (set_philo_data(*data) == -1)
		return (free((*data)->philo_data), free((*data)->threads),
			free((*data)->forks_mutexs), free(*data), -1);
	return (0);
}

static int	start_simulation(t_data *data)
{
	if (start_threads(data) == -1)
		return (printf("Erorr!\n"), -1);
	if (main_thread(data) == -1)
		return (printf("Erorr!\n"), -1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (intro(&data, ac, av) == -1)
		return (printf("Error\n"), -1);
	if (start_simulation(data) == -1)
		return (-1);
	return (0);
}
