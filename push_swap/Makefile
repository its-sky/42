# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 16:37:36 by mincshin          #+#    #+#              #
#    Updated: 2023/02/20 19:50:38 by mincshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ps

PUSH_SWAP	=	ps_push_swap

all		:	$(NAME)

$(NAME)	:
	make -C $(PUSH_SWAP)

clean	:
	make -C $(PUSH_SWAP) clean

fclean	: clean
	rm -rf	push_swap
	make -C $(PUSH_SWAP) fclean

re		: fclean all

.PHONY: all clean fclean re
