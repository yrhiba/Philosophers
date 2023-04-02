/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lltoch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 03:39:29 by yrhiba            #+#    #+#             */
/*   Updated: 2023/04/02 03:54:16 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static LL	idlen(LL id)
{
	LL	i;

	if (id == 0)
		return (1);
	i = 0;
	while (id)
	{
		id /= 10;
		i++;
	}
	return (i);
}

char	*lltoch(LL id)
{
	char	*rtn;
	LL		i;

	rtn = (char *)malloc(sizeof(char) * idlen(id) + 3);
	if (!rtn)
	{
		perror("err::malloc");
		kill(0, SIGINT);
	}
	i = idlen(id) + 2;
	rtn[i--] = '\0';
	while (i > 1)
	{
		rtn[i--] = ((id % 10) + '0');
		id /= 10;
	}
	rtn[0] = '/';
	rtn[1] = 's';
	return (rtn);
}
