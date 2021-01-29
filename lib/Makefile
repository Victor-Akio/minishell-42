# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/29 14:54:07 by jaqrodri          #+#    #+#              #
#    Updated: 2020/11/25 22:47:15 by jaqrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall \
		-Wextra\
		-Werror\

SRCS =	ft_bzero.c ft_memmove.c ft_strlen.c ft_strlcat.c ft_strlcpy.c \
		ft_memset.c ft_strncmp.c ft_strnstr.c ft_strchr.c ft_strrchr.c \
		ft_memcpy.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_isalpha.c \
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
		ft_tolower.c ft_strdup.c ft_calloc.c ft_atoi.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_itoa.c ft_putnbr_fd.c \
		ft_putendl_fd.c ft_strmapi.c ft_split.c get_next_line_utils.c get_next_line.c

SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

OBJECTS = $(SRCS:.c=.o)

OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

INCLUDES = ./
all: $(NAME)
$(NAME):
	@gcc $(FLAGS) -c $(SRCS)
	@ar -rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

bonus: $(OBJECTS) $(OBJECTS_BONUS)
	@ar -rc $(NAME) $(OBJECTS) $(OBJECTS_BONUS)
clean:
	@/bin/rm -f $(OBJECTS) $(OBJECTS_BONUS)
fclean: clean
	@/bin/rm -f $(NAME)
re: fclean all
