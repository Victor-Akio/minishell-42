/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:49:11 by vminomiy          #+#    #+#             */
/*   Updated: 2020/11/29 10:51:11 by jaqrodri         ###   ########.fr       */
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
char	*old_pwd;

typedef struct	s_commands
{
	char	***coms;
	int		com_index;
	int		index;
}				t_commands;

typedef struct	s_xy
{
	int		x;
	int		y;
}				t_xy;

int     	    main(int ac, char **av, char **ev);
void			read_input(char **input);
void			sighandler(int sig);
void			sighandler_c(int sig);
void			save_env(int ac, char **av, char **ep);
void			msh_exit(void);
char			**split_quots(char *str, char c);
void			free_all(void **buff, int len);
int				check_empty_com(char **table, char **input);
char			**rm_empty_str(char **arr);
int				count_unquoted(char **quotpos, char *str, char c);
char			**set_pos(char *str);
void			rm_quotes(char **arr);
int				tolken_gen(char **coms, t_commands *table, int size);
void			execute_com(t_commands *table, int index);
char			*non_zero_char(char *p1, char *p2);
char			*ft_strquots(char **quotpos, char *str, char c);
void			free_ptrs(t_commands *table);
void			fork_error(void);
void			com_not_found(char *str);
char			*ft_ignorechar(char **line, char c);

char			*find_envvar(char *str);
void			com_echo(char **line);
void			com_cd(char **line);
void			com_exit(void);
void			com_pwd(void);
void			com_env(void);



#endif