/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_all_the_threads.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:35:35 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/13 20:37:35 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_all_the_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philos)
		pthread_join(data->philos_threads[i], NULL);
	return (0);
}
