/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:40:40 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/30 18:26:15 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

# include <stdio.h>

typedef struct	s_lstcmds
{
	char		*name;
	int			fdin;
	int			fdout;
	char		*data;
	void		*prev;
	void		*next;
}				t_lstcmds;

typedef struct	s_msh
{
	char		*cmd_line;
	char		*path;
	char		**env;
	t_lstcmds	*cmds;
}				t_msh;

/*
 * Utils
 */
int			ft_isspace(char c);
void		ft_strdel(char **str);
int			ft_arraylen(char **str);
char		*ft_ignorechar(char **line, char c);


void		msh_exit(t_msh *msh);
char		*msh_read(t_msh *msh);
int			msh_parser(t_msh *msh);
int			msh_isseparator(char c);
void		save_env(t_msh *msh, char **ep);

int			parser_echo();//char *line, t_msh *msh)
int			parser_env(char **line, t_msh *msh);

t_lstcmds	*lcmd_last(t_lstcmds *lst);
int			lcmd_new(t_lstcmds *lcmd, char *name, char *dt, int fdi, int fdo);


#endif
