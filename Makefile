# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 20:45:56 by vminomiy          #+#    #+#              #
#    Updated: 2021/03/22 04:51:59 by vminomiy         ###   ########.fr        #
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
			$(DIR)/init.c			\
			$(DIR)/sighandler.c		\
			$(DIR)/utils.c			\
			$(DIR)/utils2.c			\
			$(DIR)/utils3.c			\
			$(DIR)/utils4.c			\
			$(DIR)/utils5.c			\
			$(DIR)/utils6.c			\
			$(DIR)/env.c			\
			$(DIR)/parser.c			\
			$(DIR)/exec.c			\
			$(DIR)/exec2.c			\
			$(DIR)/exec3.c			\
			$(DIR)/tolken.c			\
			$(DIR)/error.c			\
			$(DIR)/files.c			\
			$(DIR)/free.c			\
			$(DIR)/echo.c			\
			$(DIR)/exit.c			\
			$(DIR)/export.c			\
			$(DIR)/pwd.c			\
			$(DIR)/unset.c			\
			$(DIR)/cd.c				\
			$(DIR)/cd_utils.c
			
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