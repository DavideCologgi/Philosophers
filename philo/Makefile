# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 15:27:31 by dcologgi          #+#    #+#              #
#    Updated: 2023/05/23 11:08:51 by dcologgi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS += --silent
RM = rm -rf

SRCS_DIR = src
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = ${SRCS:.c=.o}

# Colors
DEF_COLOR = \033[0m
GRAY = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	${CC} ${OBJS} -pthread -o ${NAME}
	@echo "${GREEN}Program philo successfully compiled!${DEF_COLOR}"

all : $(NAME)

clean :
	${RM} ${OBJS}
	@echo "${BLUE}Objects cleared!${DEF_COLOR}"

fclean : clean
	rm -f ${NAME}
	@echo "${BLUE}Executable cleared!${DEF_COLOR}"

re: fclean all

.PHONY:	all clean fclean re
