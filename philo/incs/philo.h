/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:12:27 by yrhiba            #+#    #+#             */
/*   Updated: 2023/02/06 12:00:40 by yrhiba           ###   ########.fr       */
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

typedef struct s_time
{
	long long	start;

}				t_time;

typedef struct s_philo
{
	t_time		*time;
	ll			id;
	ll			*time_to_die;
	ll			*time_to_eat;
	ll			*time_to_sleep;
	ll			nums_to_eat;

}				t_philo;

typedef struct s_data
{
	t_time		time;
	ll			number_of_philos;
	ll			time_to_die;
	ll			time_to_eat;
	ll			time_to_sleep;
	ll			nums_to_eat;

}				t_data;

// floors

// floor_init
int				data_init(t_data **data);

// time
ll				get_curr_time(t_time *time);
int				set_start_time(t_time *time);

// logs
void			philo_eat(t_philo *philo);
void			philo_died(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);
void			philo_take_fork(t_philo *philo);

#endif
