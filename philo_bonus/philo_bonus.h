/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:50:22 by yrhiba            #+#    #+#             */
/*   Updated: 2023/04/02 06:01:41 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# define LL long long

# define SEC_US 1e6
# define SEC_MS 1e3

# define EAT 0
# define SLEEP 1
# define THINK 2
# define DIE 3

# define SEMFORKS "/sem_forks"
# define SEMPRINT "/sem_print"
# define SEMSYNCR "/sem_sync_"

typedef struct s_philo
{
	LL			id;

	LL			time_to_sleep;
	LL			time_to_eat;
	LL			must_eat;

	LL			start_time;
	LL			end_eattime;

	sem_t		*sem_forks;
	sem_t		*sem_print;
	sem_t		*sem_sync;

}				t_philo;

typedef struct s_data
{
	LL			number_of_philos;

	LL			time_to_die;
	LL			time_to_eat;
	LL			time_to_sleep;
	LL			must_eat;

	LL			start_time;

	sem_t		*sem_forks;
	sem_t		*sem_print;

	pid_t		*philos_ids;

	pthread_t	thread;

	t_philo		philo_data;

	LL			id;

	char		*semsync_name;
	sem_t		**sem_scyns;

}				t_data;

// intro
int				my_data_init(t_data **data, int ac, char **av);
int				alloc_needs(t_data *data);

// simulation
int				run_childs(t_data *data);
void			philo_proces(t_data *data);

// utils
LL				get_num(char *av);
LL				get_curr_time(void);
void			set_philo_data(t_data *data);
char			*lltoch(LL id);
void			mysleep(LL time_ms);

void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);

#endif
