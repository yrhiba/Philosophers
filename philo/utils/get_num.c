/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 07:01:07 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/31 07:03:24 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_num(char *av)
{
	int	i;

	i = 0;
	while (av[i] && av[i] <= '9' && av[i] >= '0')
		i++;
	if (av[i])
		return (-1);
	return (0);
}

LL	get_num(char *av)
{
	LL	num;

	if (is_num(av) == -1)
		return (-1);
	num = 0;
	while (*av)
		num = num * 10 + (*(av++) - '0');
	return (num);
}
