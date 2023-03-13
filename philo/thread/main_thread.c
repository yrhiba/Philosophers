/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:28:08 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/13 20:52:28 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main_thread(t_data *data)
{
	while (1)
	{
		printf("main thread routine philos alive : %lld \n", data->number_of_philos);
		usleep(5 * 1e6);
	}
	return (0);
}
