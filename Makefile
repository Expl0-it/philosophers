# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 10:27:39 by mamichal          #+#    #+#              #
#    Updated: 2024/10/28 11:57:45 by mamichal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -fr
INCLUDES = ./includes/philo.h

SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -include $(INCLUDES)

${NAME}: $(OBJS)
	${CC} ${FLAGS} -o ${NAME} $(OBJS) -include $(INCLUDES)
	echo Compiling Executable

all: ${NAME}

bonus: ${NAME}

clean:
	${RM} *.o */*.o */*/*.o
	echo Only Exec Left

fclean: clean
	${RM} ${NAME}
	echo All Clean

re: fclean all

.SILENT:

.PHONY: all clean fclean re
