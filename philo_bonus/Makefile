# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 08:58:04 by yrhiba            #+#    #+#              #
#    Updated: 2023/04/02 07:12:39 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRCS =	philo_bonus.c \
		intro/alloc_needs.c \
		intro/my_data_init.c \
		simulation/run_childs.c \
		simulation/philo_proces.c \
		utils/get_curr_time.c \
		utils/philo_utils.c \
		utils/mysleep.c \
		utils/get_num.c \
		utils/set_philo_data.c \
		utils/lltoch.c


INCS = philo_bonus.h

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror #-fsanitize=thread

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(FLAGS)
	make clean

%.o : %.c $(INCS)
	$(CC) -c $< -o $@ -I . $(FLAGS)

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONEY : all clean fclean re
