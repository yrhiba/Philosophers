# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 10:35:12 by yrhiba            #+#    #+#              #
#    Updated: 2023/03/13 18:33:01 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

OBJFLAGS = -Wall -Wextra -Werror
INCSPATH = -I incs

SRCS =	philo.c \
		parse/my_data_init.c \
		logs/logs.c \
		utils/get_num.c \
		utils/set_start_time.c \
		utils/get_curr_time.c \
		utils/calc_curr_time.c \
		utils/creat_forks_mutex.c \
		utils/alloc_needs.c \
		utils/allocat_philos_data.c \
		thread/philo_thread.c


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
