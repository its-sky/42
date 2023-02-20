# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/04 19:56:08 by mincshin          #+#    #+#              #
#    Updated: 2022/07/09 13:51:28 by mincshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
CFLAGS= -c -Wall -Wextra -Werror
OBJS= $(SRCS:.c=.o)
OBJS_BONUS= $(SRCS_BONUS:.c=.o)
INCS= ./libft.h
SRCS= ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c \
		ft_toupper.c ft_atoi.c ft_bzero.c ft_memcmp.c ft_memchr.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strchr.c ft_strrchr.c \
		ft_strnstr.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRCS_BONUS= ft_lstnew.c ft_lstsize.c ft_lstadd_front.c ft_lstadd_back.c ft_lstclear.c ft_lstlast.c \
			ft_lstiter.c ft_lstmap.c ft_lstdelone.c
NAME= libft.a

ifdef WITH_BONUS
	OBJ = $(OBJS) $(OBJS_BONUS)
else
	OBJ = $(OBJS)
endif

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -I $(INCS) -o $@

$(NAME): $(OBJ)
	ar rcs $@ $^

bonus:
	make WITH_BONUS=1 all

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re
