# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 22:06:55 by yrhiba            #+#    #+#              #
#    Updated: 2023/03/17 22:23:25 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

OBJFLAGS = -Wall -Wextra -Werror
INCSPATH = -I incs

SRCS =	philo.c \
		utils/my_data_init.c \
		utils/get_num.c


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
