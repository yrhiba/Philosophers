/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:57:36 by yrhiba            #+#    #+#             */
/*   Updated: 2023/04/02 08:39:22 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	intro(t_data **data, int ac, char **av)
{
	if (my_data_init(data, ac, av) == -1)
		return (-1);
	if (alloc_needs(*data) == -1)
		return (free(*data), -1);
	set_philo_data(*data);
	return (0);
}

static int	start_simulation(t_data *data)
{
	if (run_childs(data) == -1)
		kill(0, SIGINT);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;
	LL		i;

	i = -1;
	if (intro(&data, ac, av) == -1)
		return (printf("Erorr\n"), 0);
	if (start_simulation(data) == -1)
		kill(0, SIGINT);
	while (++i < data->number_of_philos)
		waitpid(data->philos_ids[i], NULL, 0);
	return (kill(0, SIGINT), 0);
}
