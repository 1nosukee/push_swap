# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfaouzi <wfaouzi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 00:39:15 by wfaouzi           #+#    #+#              #
#    Updated: 2023/10/22 15:58:21 by wfaouzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = push_swap

CC = cc

GCC = -Wall -Wextra -Werror

SRCS =	push_swap.c parse.c range.c utils.c utils2.c  rules.c \
		rules2.c stack.c sort.c \
		
OBJECTS = push_swap.o parse.o range.o utils.o utils2.o rules.o \
		rules2.o stack.o sort.o \
		
LIBFT = ./libft/libft.a

%.o : %.c
	$(CC) $< $(GCC) -c -o $@

all: ${NAME}

$(LIBFT) :
	$(MAKE) -C libft

${NAME}: $(OBJECTS) $(LIBFT)
	${CC} ${GCC} ${SRCS} ${LIBFT} -o ${NAME}

clean:
	make clean -C ./libft/
	rm -rf ${OBJECTS}

fclean: clean
	rm -rf ${OBJECTS} ${NAME} ${LIBFT}

re: fclean all
