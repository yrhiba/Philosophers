/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:06:51 by yrhiba            #+#    #+#             */
/*   Updated: 2023/03/18 04:28:50 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define EXIT_SUCCES 0
# define EXIT_ERR 1
# define EXIT_DIE 2

# define LL long long

# define SEC_US 1e6
# define SEC_MS 1e3

# define EAT 0
# define SLEEP 1
# define THINK 2
# define DIE 3

# define SEMFORKS "/sem_forks"

typedef struct s_time
{
	long long	time;

}				t_time;

typedef struct s_philo
{
	LL			id;
	LL			he_is;

	LL			*time_to_sleep;
	LL			*time_to_eat;
	LL			nums_to_eat;

	t_time		*start_time;
	t_time		end_eattime;

	sem_t		*sem_forks;

	LL			*error;

}				t_philo;

typedef struct s_data
{
	LL			number_of_philos;
	LL			time_to_die;
	LL			time_to_eat;
	LL			time_to_sleep;
	LL			nums_to_eat;

	t_time		start_time;

	t_philo		philo_data;

	sem_t		*sem_forks;
	pid_t		*philos_ids;

	pthread_t	philo_thread;

	LL			error;

}				t_data;

// utils one
int				alloc_needs(t_data *data);
LL				calc_curr_time(t_philo *philo);
LL				get_curr_time(void);
LL				get_num(char *av);
int				my_data_init(t_data **data, int ac, char **av);
int				open_semaphore(t_data *data);
int				set_start_time(t_data *data);

// utils one
int				start_philos_cycle(t_data *data);

// logs
int				philo_eat(t_philo *philo);
int				philo_died(t_philo *philo);
int				philo_sleep(t_philo *philo);
int				philo_think(t_philo *philo);
int				philo_take_fork(t_philo *philo);

// process
int				main_proces(t_data *data);
void			philo_proces(t_data *data);

// clean
void			clean_one(t_data *data);
void			clean_two(t_data *data);

#endif
