/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:12:27 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/10 22:10:33 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define EXIT_ERR 1
# define EXIT_SUCCES 1

# define ll long long

# define SEC_US ((ll)1e6)
# define SEC_MS ((ll)1e3)

# define EAT 0
# define SLEEP 1
# define THINK 2

typedef struct s_time
{
	long long	time;

}				t_time;

typedef struct s_philo
{
	ll			id;
	ll			*time_to_die;
	ll			*time_to_eat;
	ll			*time_to_sleep;
	ll			nums_to_eat;
	ll			he_is;
	t_time		*start_time;
	t_time		start_eat;
	t_time		end_eat;

}				t_philo;

typedef struct s_data
{
	ll			number_of_philos;
	ll			time_to_die;
	ll			time_to_eat;
	ll			time_to_sleep;
	ll			nums_to_eat;
	t_time		start_time;

}				t_data;

// parsing
int				my_data_init(t_data **data, int ac, char **av);


// logs
// void			philo_eat(t_philo *philo);
// void			philo_died(t_philo *philo);
// void			philo_sleep(t_philo *philo);
// void			philo_think(t_philo *philo);
// void			philo_take_fork(t_philo *philo);

// utils
ll				get_num(char *av);

#endif
