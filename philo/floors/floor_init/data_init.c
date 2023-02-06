/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:08:47 by yrhiba            #+#    #+#             */
/*   Updated: 2023/02/06 12:00:34 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	data_init(t_data **data)
{
	*data = (t_data *)malloc(sizeof(t_data));
	if (!(*data))
		return (perror("error"), exit(EXIT_ERR), -1);
	return ((*data)->nums_to_eat = INT_MAX, 0);
}
