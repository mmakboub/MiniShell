# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 16:03:37 by mmakboub          #+#    #+#              #
#    Updated: 2022/12/26 20:05:56 by mmakboub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
FONCTIONS = ./exect/cd.c\
			./exect/echo2.c\
			./exect/env.c\
			./exect/exit.c\
			./exect/export.c\
			./exect/is_builting.c\
			./exect/pipe.c\
            ./exect/pwd.c\
            ./exect/unset.c\
            ./exect/utils.c\
            ./exect/envirement/build_envirement.c\
            ./exect/envirement/env_initialisation.c\
	
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
INCLUDE = ./exect/minishell.h

OBJS = $(FONCTIONS:.c=.o)


all : $(NAME)

$(NAME):	$(OBJS)	$(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME) 

re: fclean all
