# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 12:18:16 by hbuisser          #+#    #+#              #
#    Updated: 2020/11/25 20:05:21 by vminomiy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_free.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
ft_toupper.c ft_strncpy.c ft_strcmp.c ft_putstr.c ft_putchar.c ft_putnbr.c \
ft_arraylen.c get_next_line.c ft_memalloc.c ft_memdel.c ft_vcalloc.c \
ft_intlen.c ft_isspace.c ft_freearray.c ft_iswall.c ft_addchar.c ft_addstr.c \
ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
ft_lstadd_back_bonus.c ft_lstlast_bonus.c ft_lstclear_bonus.c \
ft_lstdelone_bonus.c ft_lstiter_bonus.c

OBJECTS = $(SRCS:%.c=%.o)

CC = gcc

REM = rm -rf

HEADER = ./

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(OBJECTS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

clean:
	$(REM) $(OBJECTS)

fclean: clean
	$(REM) $(NAME)

re: fclean all
.PHONY: all clean fclean re
