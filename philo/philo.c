/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 03:47:44 by yrhiba            #+#    #+#             */
/*   Updated: 2023/02/06 12:00:40 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int parse(t_philo *philo, int ac, char **av)
// {
// 	if (ac != 4 && ac != 5)
// 		return (-1);
// 	philo->number_of_philosophers = av[1];
// 	philo->time_to_die = av[2];
// 	philo->time_to_eat = av[3];
// 	philo->number_of_times_each_philosopher_must_eat = INT_MAX;
// 	if (ac == 5)
// 		philo->number_of_times_each_philosopher_must_eat = av[4];
// 	return (-1);
// }

int main(int ac, char **av)
{
	t_data	*data;

	data_init(&data);
	free(data);
	return (EXIT_SUCCES);
}
