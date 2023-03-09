# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 10:35:12 by yrhiba            #+#    #+#              #
#    Updated: 2023/03/09 15:39:00 by yrhiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

OBJFLAGS = -Wall -Wextra -Werror
INCSPATH = -I incs

SRCS =	$(SRCS_MYLIST) \
		philo.c \
		floors/floor_init/data_init.c \
		logs/logs.c \
		utils/time/time.c

SRCS_MYLIST =	mylist/my_list_init.c \
				mylist/my_list_clear.c \
				mylist/my_list_new_elem.c \
				mylist/my_list_push_back.c \
				mylist/my_list_push_front.c \
				mylist/my_list_front.c \
				mylist/my_list_back.c \
				mylist/my_list_empty.c \
				mylist/my_list_size.c \
				mylist/my_list_pop_front.c \
				mylist/my_list_pop_back.c \
				mylist/my_list_get.c \
				mylist/my_list_erase.c \
				mylist/my_list_insert.c

INCS = incs/my_list.h incs/philo.h

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
