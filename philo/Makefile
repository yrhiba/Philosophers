# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 10:35:12 by yrhiba            #+#    #+#              #
#    Updated: 2023/03/13 20:37:36 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

OBJFLAGS = -Wall -Wextra -Werror
INCSPATH = -I incs

SRCS =	philo.c \
		parse/my_data_init.c \
		logs/logs.c \
		utils_one/get_num.c \
		utils_one/set_start_time.c \
		utils_one/get_curr_time.c \
		utils_one/calc_curr_time.c \
		utils_one/creat_forks_mutex.c \
		utils_one/alloc_needs.c \
		utils_one/allocat_philos_data.c \
		utils_two/start_philos_cycle.c \
		utils_two/join_all_the_threads.c \
		thread/philo_thread.c \
		thread/main_thread.c

INCS = incs/philo.h

ODIR = objs/
OBJS = $(addprefix $(ODIR), $(SRCS:.c=.o))

$(NAME) : $(OBJS)
	cc $(OBJS) -o $(NAME)

all : $(NAME)

$(ODIR)%.o : %.c $(INCS)
	@mkdir -p $(dir $@)
	cc $(OBJFLAGS) -c $< -o $@ $(INCSPATH)

clean :
	rm -rf $(ODIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONEY : all fclean clean re
