# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mincshin <mincshin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 13:30:20 by mincshin          #+#    #+#              #
#    Updated: 2023/03/15 14:45:53 by mincshin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 
SERVER_NAME = server
CLIENT_NAME = client

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SERVER_FILE = server.c \
				lib.c \
				lib2.c

CLIENT_FILE = client.c \
				lib.c \
				lib2.c

SRC_DIR = ./src
SERVER_SRCS = $(addprefix $(SRC_DIR)/, $(SERVER_FILE))
CLIENT_SRCS = $(addprefix $(SRC_DIR)/, $(CLIENT_FILE))

OBJ_DIR = ./obj
SERVER_OBJS = $(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(SERVER_FILE)))
CLIENT_OBJS = $(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(CLIENT_FILE)))

export SERVER_FILE
export CLIENT_FILE

all : $(SERVER_NAME) $(CLIENT_NAME)

$(NAME) : all

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_NAME) : $(SERVER_OBJS)
		$(CC) $(CFLAGS) -o $@ $^

$(CLIENT_NAME) : $(CLIENT_OBJS)
		$(CC) $(CFLAGS) -o $@ $^

clean :
		rm -rf $(OBJ_DIR)

fclean : clean
		rm -f $(SERVER_NAME) $(CLIENT_NAME)

re : fclean all

.PHONY : clean fclean all re