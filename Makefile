# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 20:45:56 by vminomiy          #+#    #+#              #
#    Updated: 2020/11/29 11:05:38 by jaqrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

CC		=	clang

LIB_DIR	=	./libft

LIB		=	$(LIB_DIR)/libft.a

DIR	=	./srcs

CC_FLAG =	-c		\
			-Wall	\
			-Wextra	\
			-Werror	\

INCLUDE	=	-I ./include	\
			-I $(LIB_DIR)

RM		=	/bin/rm -f

SRC		=	$(DIR)/main.c			\
			$(DIR)/sighandler.c		\
			$(DIR)/utils.c			\
			$(DIR)/gnl.c			\
			$(DIR)/env.c			\
			$(DIR)/parser.c			\
			$(DIR)/exec.c			\
			$(DIR)/com_echo.c		\
			$(DIR)/com_pwd.c		\
			$(DIR)/com_cd.c			\
			$(DIR)/com_env.c		\
			$(DIR)/ft_ignorechar.c	\
			$(DIR)/find_envvar.c	\
			$(DIR)/exit.c
			

OBJ		=	$(patsubst %.c, %.o, ${SRC})

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(LIB)
			$(CC) -fsanitize=address $(ML_FLAG) -o $@ $^

%.o		:	%.c
			$(CC) -g $(CC_FLAG) $(INCLUDE) $< -o $@

$(LIB)	:
			$(MAKE) -C $(LIB_DIR)

clean	:
			for dir in $(MODULES); do	\
				$(MAKE) clean -C $$dir;	\
			done
			$(RM) $(OBJ)

fclean	:	clean
			$(MAKE) fclean -C $(LIB_DIR)
			$(RM) $(NAME)

re		:	fclean all