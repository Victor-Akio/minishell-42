# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/02 00:38:44 by jaqrodri          #+#    #+#              #
#    Updated: 2020/11/26 17:37:13 by jaqrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT_DIR = ./lib
LIBFT = ${LIBFT_DIR}/libft.a

INCLUDE_DIR = ./include

CC = gcc
CC_FLAGS =	-g \
			-c \
			-Wall \
			-Wextra \
			-Werror \
			-I${LIBFT_DIR} \
			-I${INCLUDE_DIR}

LD_FLAGS =	-L${LIBFT_DIR}	\
			-lft 

SRC_DIR = ./src
SRC =	${SRC_DIR}/main.c \
		${SRC_DIR}/ft_strdel.c \
		${SRC_DIR}/ft_isspace.c \
		${SRC_DIR}/ft_ignorechar.c \
		${SRC_DIR}/parser_echo.c \
		${SRC_DIR}/msh_parser.c \
		${SRC_DIR}/msh_read.c 

OBJ_DIR	=	./objects
OBJ		=	$(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC})


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^  $(LD_FLAGS) -o $@
	
	# $(CC) -fsanitize=address $^  $(LD_FLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ${LIBFT} 
	mkdir -p $(OBJ_DIR)
	$(CC) $(CC_FLAGS) $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C ${LIBFT_DIR} clean; \
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C ${LIBFT_DIR} fclean;
	$(RM) $(NAME)

re: clean all

test: all
	./$(NAME)
