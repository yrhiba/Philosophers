/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pros.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 04:27:16 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/18 11:45:31 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main_proces(t_data *data)
{
	LL	i;
	
	while (1)
	{
		/* code */
	}
	i = -1;
	while (++i < data->number_of_philos)
		waitpid(data->philos_ids[i], NULL, 0);
	return (0);
}
