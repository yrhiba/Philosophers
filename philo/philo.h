/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:12:27 by yrhiba            #+#    #+#             */
/*   Updated: 2023/02/06 05:10:13 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <error.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define SEC_US 1000000
# define SEC_MS 1000
# define ll long long

// struct timeval {
// 			time_t      tv_sec;     /* seconds */
// 			suseconds_t tv_usec;    /* microseconds */
// };

// typedef struct s_philo

typedef struct s_time
{
	long long		start;
	long long		curr;

}					t_time;

typedef struct s_philo
{
	pthread_t		*threads;
	pthread_mutex_t	*mutexs;
	ll				number_of_philos;
	ll				time_to_die;
	ll				time_to_eat;
	ll				time_to_sleep;
	ll				time_must_eat;
	ll				start_time_ms;

}					t_philo;

// time
int					set_curr_time(t_time *time);
int					set_start_time(t_time *time);

#endif
