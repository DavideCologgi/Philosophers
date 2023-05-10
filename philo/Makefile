# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcologgi <dcologgi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 15:27:31 by dcologgi          #+#    #+#              #
#    Updated: 2023/05/10 10:02:28 by dcologgi         ###   ########.fr        #
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
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	@echo "${GREEN}Program philo successfully compiled!${DEF_COLOR}"

all : $(NAME)

clean :
	${RM} ${OBJS}
	@echo "$(BLUE)Objects cleared!$(DEF_COLOR)"

fclean : clean
	rm -f $(NAME)
	@echo "$(BLUE)Executable cleared!$(DEF_COLOR)"

re: fclean all

.PHONY:	all clean fclean re
