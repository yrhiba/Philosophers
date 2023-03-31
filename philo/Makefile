# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 06:04:50 by yrhiba            #+#    #+#              #
#    Updated: 2023/03/31 22:40:40 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS =	philo.c \
		intro/alloc_needs.c \
		intro/creat_forks_mutex.c \
		intro/my_data_init.c \
		intro/set_philo_data.c \
		simulation/main_thread.c \
		simulation/philo_thread.c \
		simulation/start_simulation.c \
		utils/clean.c \
		utils/get_curr_time.c \
		utils/get_num.c \
		utils/mysleep.c \
		utils/philo_thread_utils.c


INCS = philo.h

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror #-fsanitize=thread

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.c $(INCS)
	cc $(FLAGS) -c $< -o $@ -I .

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONEY : all clean fclean re
