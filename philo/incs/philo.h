/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:12:27 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/11 23:14:28 by yrhiba           ###   ########.fr       */
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
# define EXIT_SUCCES 0

# define LL long long

# define SEC_US 1e6
# define SEC_MS 1e3

# define EAT 0
# define SLEEP 1
# define THINK 2

typedef struct s_time
{
	long long		time;

}					t_time;

typedef struct s_data
{
	pthread_t		*philos_threads;
	pthread_mutex_t	*forks_mutex;
	LL				number_of_philos;
	LL				time_to_die;
	LL				time_to_eat;
	LL				time_to_sleep;
	LL				nums_to_eat;
	LL				error;
	t_time			start_time;

}					t_data;

typedef struct s_philo
{
	LL				id;
	LL				nums_to_eat;
	LL				he_is;
	t_time			start_time;
	t_time			end_time;
	t_data			*data;

}					t_philo;

// parsing
int					my_data_init(t_data **data, int ac, char **av);

// logs
int					philo_eat(t_philo *philo);
int					philo_died(t_philo *philo);
int					philo_sleep(t_philo *philo);
int					philo_think(t_philo *philo);
int					philo_take_fork(t_philo *philo);

// utils
LL					calc_curr_time(t_philo *philo);
LL					get_num(char *av);
LL					get_curr_time(void);
int					set_start_time(t_data *data);
int					creat_forks_mutex(t_data *data);
int					alloc_needs(t_data *data);

// philo thread
void				*philo_thread(void *arg);

#endif
