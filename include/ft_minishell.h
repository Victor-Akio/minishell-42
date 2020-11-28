/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:40:40 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/27 19:22:13 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

# include <stdio.h>

// typedef struct	s_lstcmds
// {
// 	char		*name;
// 	int			type;
// 	// int			pipe[2];
// 	char		**data;
// 	void		*prev;
// 	void		*next;
// }				t_lstcmds;

typedef struct	s_msh
{
	char		*command;
}				t_msh;

/*
 * Utils
 */
void	ft_strdel(char **str);
char	*ft_ignorechar(char **line, char c);
int		ft_isspace(char c);

char	*msh_read(t_msh *msh);
int		msh_parser(t_msh *msh);

int		parser_echo();//char *line, t_msh *msh)




#endif
