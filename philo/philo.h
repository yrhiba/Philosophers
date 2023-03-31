/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 06:41:22 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/31 21:37:54 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/random.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# define SEC_US 1e6
# define SEC_MS 1e3

# define EAT 0
# define SLEEP 1
# define THINK 2
# define DIE 3

# define LL long long

typedef struct s_philo
{
	LL				id;
	LL				he_is;
	LL				time_to_sleep;
	LL				time_to_eat;
	LL				time_to_die;
	LL				must_eat;
	LL				start_time;
	LL				end_eat_time;
	LL				error;

	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;

	pthread_mutex_t	mutex_id;
	pthread_mutex_t	mutex_he_is;
	pthread_mutex_t	mutex_must_eat;
	pthread_mutex_t	mutex_error;
	pthread_mutex_t	mutex_endtime;

	pthread_mutex_t	*print_mutex;

}					t_philo;

typedef struct s_data
{
	LL				number_of_philos;

	LL				time_to_sleep;
	LL				time_to_eat;
	LL				time_to_die;
	LL				must_eat;

	LL				start_time;

	pthread_t		*threads;
	pthread_mutex_t	*forks_mutexs;

	t_philo			*philo_data;

	pthread_mutex_t	print_mutex;

}					t_data;

// intro
int					my_data_init(t_data **data, int ac, char **av);
int					alloc_needs(t_data *data);
int					creat_forks_mutex(t_data *data);
int					set_philo_data(t_data *data);

// simulation
int					start_threads(t_data *data);
void				*philo_thread(void *data);
int					main_thread(t_data *data);

// utils
LL					get_num(char *av);
void				destroy_mutexs(t_data *data, LL size);
int					clean(t_data *data);
LL					get_curr_time(void);
void				mysleep(LL time_ms);

void				philo_eat(t_philo *philo);
void				philo_err(t_philo *philo);
void				philo_sleep(t_philo *philo);
void				philo_think(t_philo *philo);
void				philo_die(t_philo *philo);

#endif
