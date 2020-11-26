/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:49:11 by vminomiy          #+#    #+#             */
/*   Updated: 2020/11/26 00:52:03 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include "../libft/libft.h"

# include <stdio.h> //DELETAAAAAAAAAR

char	**tmp_env;

int     	    main(int ac, char **av, char **ev);
void			read_input(char **input);
void			sighandler(int sig);
void			sighandler_c(int sig);
void			save_env(int ac, char **av, char **ep);
void			msh_exit(void);
char			**split_quots(char *str, char c);

#endif