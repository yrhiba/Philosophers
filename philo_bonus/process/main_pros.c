/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pros.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 04:27:16 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/18 05:37:04 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static LL	get_id(t_data *data, pid_t pid)
{
	LL	i;

	i = -1;
	while (++i < data->number_of_philos)
	{
		if (pid == data->philos_ids[i])
			return (i);
	}
	return (-1);
}

static void	kill_all_philos(t_data *data)
{
	LL	i;

	i = -1;
	while (++i < data->number_of_philos)
		kill(data->philos_ids[i], SIGKILL);
}

int	main_proces(t_data *data)
{
	pid_t	pid;
	int		*ex_v;
	LL		returned_philo;

	returned_philo = 0;
	while (returned_philo < data->number_of_philos)
	{
		pid = waitpid(-1, ex_v, 0);
		data->philo_data.id = get_id(data, pid);
		if (data->philo_data.id == -1)
			return (-1);
		if (WEXITSTATUS(ex_v) == EXIT_DIE)
		{
			kill_all_philos(data);
			if (philo_died(&(data->philo_data)) == -1)
				return (-1);
			return (0);
		}
		else if (WEXITSTATUS(ex_v) == EXIT_SUCCES)
			returned_philo++;
		else
			return (kill_all_philos(data), -1);
	}
	return (0);
}
