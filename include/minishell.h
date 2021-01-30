/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:49:11 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/30 05:28:34 by vminomiy         ###   ########.fr       */
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

typedef struct	s_commands
{
	char	***coms;
	int		com_index;
	char	***i_files;
	char	***o_files;
	char	***ap_files;
	char	***d_files;
	int		index;
}				t_commands;

typedef struct	s_var
{
	int		count;
	int		i;
	int		j;
}				t_var;
/*
** Functions
*/
void			msh_exit(void);
void			com_exit(void);
void			com_echo(char **arg);
void			com_env(char **arg);
void			com_pwd(char **arg);
void			com_unset(char **arg);
void			com_export(char **arg);
int				com_cd(char **arg);
/*
** GNL
*/
void			read_input(char **input);
/*
** Parser
*/
int				tolken_gen(char **coms, t_commands *table, int size);
void			init_redirection(t_commands *table, int *i, int *count);
/*
** Executor
*/
int				coms_handler(char **arr);
void			pick_com_exec(char **arr, t_commands *table);
char			*env_handler(char *ev);
char			**save_syspath(void);
int				sys_path(char **arr);
int				exec_pathfinder(char **arr);
void			launch_exec(char **arr);
void			execute_com(t_commands *table, int index);
/*
** Utilities
*/
void			count_redirections(char **arr, int *count);
void			save_env(int ac, char **av, char **ep);
char			**split_quots(char *str, char c);
char			**rm_empty_str(char **arr);
char			*ft_strquotsbase(char **quotpos, char *str, char c);
char			*ft_strquots(char **quotpos, char *str, char c);
char			*ft_strquot_aux(char **quotpos, char *str, char c);
int				count_unquoted(char **quotpos, char *str, char c);
int				between_quot_pair(char **quotpos, char *pos);
void			rm_dummies(char **table);
char			*non_zero_char(char *p1, char *p2);
void			rm_quotes(char **arr);
char			**set_pos(char *str);
char			*dup_symbol(char *str);
void			resize_arr_pos(char ***arr, int pos);
int				set_redirection(t_commands *table, int *i);
void			count_redirections(char **arr, int *count);
void			redir_files_updt(t_commands *table, int *i, char *str, int index);
int				envp_len(char **envp);
int				input_minishell(char **input, char c);
int				quote_handler(char **arg, int i);
void			replace_var(char **dir, char *ptr);
void			replace_env(t_commands *table);
void			rm_backslash(char **strdir, char *slashpos);
char			*set_env(char *arg);
char			**set_pos(char *str);
void			export_no_arg(char **tmp);
int				read_subshell(char **input, char c);
char			*env_selector(char *ev);
t_var			reset_count(void);
void			show_prompt(void);
/*
** Free malloc
*/
void			free_ptrs(t_commands *table);
void			free_table(t_commands *table, int index);
int				free_parser_error(t_commands *table, int index, char **coms);
void			free_all(void **buff, int len);
void			free_array(char **str);
/*
** Error
*/
int				parser_error(t_commands *table, int i);
void			fork_error(void);
void			coms_not_found(char *str);
/*
** Signal
*/
void			sighandler(int sig);
void			sighandler_c(int sig);

#endif