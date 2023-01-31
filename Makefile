# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 04:13:27 by mmakboub          #+#    #+#              #
#    Updated: 2023/01/31 19:00:12 by mmakboub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell
FONCTIONS = ./exect/about_cd.c ./exect/cd.c\
			./exect/echo2.c\
			./exect/about_env.c ./exect/env.c\
			./exect/exit.c\
			./exect/export.c ./exect/export_errors.c ./exect/export_utils.c\
			./exect/is_builting.c\
			./exect/pipe.c ./exect/pipe_utils.c\
            ./exect/pwd.c\
            ./exect/unset.c\
            ./exect/utils.c\
            ./exect/build_envirement.c\
            ./exect/env_initialisation.c\
			./exect/execve_errors.c\
			./exect/execve.c ./libft/ft_memset.c\
			./utils/ft_strjoin.c\
			./libft/ft_isprint.c\
			./libft/ft_putchar_fd.c ./libft/ft_strlcat.c\
			./utils/ft_substr.c ./libft/ft_atoi.c\
			./utils/ft_itoa.c ./libft/ft_putendl_fd.c\
			./libft/ft_strlcpy.c ./libft/ft_isdigit.c\
			./libft/ft_bzero.c ./libft/ft_putnbr_fd.c\
			./libft/ft_strlen.c ./libft/ft_toupper.c ./libft/ft_calloc.c\
			./libft/ft_memchr.c ./libft/ft_putstr_fd.c\
			./libft/ft_strmapi.c ./libft/ft_isalnum.c\
			./libft/ft_memcmp.c ./libft/ft_strncmp.c\
			./libft/ft_isalpha.c ./utils/ft_split.c\
			./libft/ft_memcpy.c ./libft/ft_strchr.c\
			./libft/ft_strnstr.c ./libft/ft_tolower.c\
			./libft/ft_memmove.c ./utils/ft_strdup.c\
			./libft/ft_strrchr.c ./libft/ft_strcmp.c\
			./parsing/delete_qote.c\
			./parsing/expender.c\
			./parsing/herdoc_expender.c\
			./parsing/expender_utils.c\
			./parsing/grammar.c\
			./parsing/grammar_utils.c\
			./parsing/parser.c\
			./parsing/tokeniser.c\
			./parsing/tokeniser_utils.c ./parsing/tokeniser_utils2.c\
			./parsing/utils.c ./parsing/utils2.c\
			./exect/redirection.c\
			./exect/execution.c ./exect/signals2.c\
			./main.c ./exect/signals.c\
			./free.c

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
INCLUDE = minishell.h
LFLAGS = -L/Users/mmakboub/.brew/opt/readline/lib 
IFLAGS = -I/Users/mmakboub/.brew/opt/readline/include 

OBJS = $(FONCTIONS:.c=.o)

all : $(NAME)

$(NAME) :	$(OBJS)	$(INCLUDE)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME) -lreadline -lncurses $(LFLAGS)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME) 

re: fclean all