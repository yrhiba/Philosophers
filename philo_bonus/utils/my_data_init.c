/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_data_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:15:30 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/17 22:20:05 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_data(t_data *data)
{
	if (data->number_of_philos == -1 || data->nums_to_eat == -1
		|| data->time_to_die == -1 || data->time_to_sleep == -1
		|| data->time_to_eat == -1 || data->number_of_philos == 0)
		return (-1);
	return (0);
}

static int	parse_data(t_data *data, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (-1);
	data->number_of_philos = get_num(av[1]);
	data->time_to_die = get_num(av[2]);
	data->time_to_eat = get_num(av[3]);
	data->time_to_sleep = get_num(av[4]);
	data->nums_to_eat = INT_MAX;
	if (ac == 6)
		data->nums_to_eat = get_num(av[5]);
	return (check_data(data));
}

int	my_data_init(t_data **data, int ac, char **av)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if (!(*data))
		return (-1);
	if (parse_data(*data, ac, av) == -1)
		return (free(*data), -1);
	return (0);
}
