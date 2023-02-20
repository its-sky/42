# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 16:36:58 by mincshin          #+#    #+#              #
#    Updated: 2023/02/20 19:44:45 by mincshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	../push_swap

SRCS_DIR	=	src/
SRCS_BASE	=	push_swap.c utils.c greedy.c command.c command2.c etc.c parse.c
OBJS		=	$(SRCS:%.c=%.o)
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_BASE))

INC	=	include

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-Llibft -l_mincshin
LIBFT	=	libft

all		:	$(NAME)

$(NAME)	:	$(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(CLIB) -I $(INC) $(OBJS) -o $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -rf $(OBJS)
	make -C $(LIBFT) clean

fclean	: clean
	rm -rf	$(NAME)
	make -C $(LIBFT) fclean

re		: fclean all

.PHONY: all clean fclean re
