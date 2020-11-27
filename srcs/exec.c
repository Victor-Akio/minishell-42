/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:01:58 by vminomiy          #+#    #+#             */
/*   Updated: 2020/11/27 22:58:50 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			free_ptrs(t_commands *table)
{
	free(table->coms);
	// free(table->i_files);
	// free(table->o_files);
	// free(table->ap_files);
	// free(table->d_files);
}

void			free_table(t_commands *table, int index)
{
	int 		i;
	int			j;

	i = -1;
	while (++i < index)
	{
		j = -1;
		while (++j < table[i].com_index)
		{
			free_all((void **)table[i].coms[j], ft_arraylen(table[i].coms[j]));
			// free_all((void **)table[i].i_files[j], ft_arraylen(table[i].i_files[j]));
			// free_all((void **)table[i].o_files[j], ft_arraylen(table[i].o_files[j]));
			// free_all((void **)table[i].ap_files[j], ft_arraylen(table[i].ap_files[j]));
			// free_all((void **)table[i].d_files[j], ft_arraylen(table[i].d_files[j]));
		}
		free_ptrs(table + i);
	}
	free(table);
}

static void		reset_values(int *fd)
{
	dup2(fd[0], 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
}

int				coms_handler(char **arr)
{
	if (!arr[0])
		return (0);
	else if (!(ft_strcmp(arr[0], "echo")))
		return (1);
	else if (!(ft_strcmp(arr[0], "cd")))
		return (1);
	else if (!(ft_strcmp(arr[0], "pwd")))
		return (1);
	else if (!(ft_strcmp(arr[0], "export")))
		return (1);
	else if (!(ft_strcmp(arr[0], "unset")))
		return (1);
	else if (!(ft_strcmp(arr[0], "env")))
		return (1);
	else if (!(ft_strcmp(arr[0], "exit")))
		return (1);
	else
		return (0);
}

void			pick_com_exec(char **arr, t_commands *table)
{
	table->index = 0;
	if (!(ft_strcmp(arr[0], "echo")))
		com_echo(arr);
	// else if (!(ft_strcmp(arr[0], "cd")) && !((table->coms != 1)
	// 	&& (ft_arrlen(arr) == 1)))
	// 	com_cd(arr);
	// else if (!(ft_strcmp(arr[0], "pwd")))
	// 	com_pwd(arr);
	// else if (!(ft_strcmp(arr[0], "export")) && (table->coms == 1))
	// 	com_export(arr);
	// else if (!(ft_strcmp(arr[0], "unset")) && (table->coms == 1))
	// 	com_unset(arr);
	// else if (!(ft_strcmp(arr[0], "env")))
	// 	com_env(arr);
	else if (!(ft_strcmp(arr[0], "exit")))
		com_exit();
}

char			*env_handler(char *ev)
{
	int			len;
	char		*res;
	int			i;

	i = -1;
	while (ev[++i] && (ev[i] != ' ') && (ev[i] != '\t') && (ev[i] != '\'') && (ev[i] != '"') && (ev[i]  != '\n'))
		;
	len = i;
	i = 0;
	while (tmp_env[i] && ft_strncmp(ev, tmp_env[i], len) != 0)
		i++;
	if (!tmp_env[i] || tmp_env[i][len] != '=')
		res = ft_strdup("");
	else
		res = ft_substr(tmp_env[i], len + 1, ft_strlen(tmp_env[i]));
	return (res);
}

char			**save_syspath(void)
{
	char		*tmp;
	char		**path;
	int			count;
	int			i;
	int			j;

	count = 0;
	i = 0;
	j = 0;
	tmp = env_handler("PATH");
	if (tmp[ft_strlen(tmp) - 1] != ':')
		tmp = ft_addchar(tmp, ':');
	while (tmp[++i])
		if (tmp[i] == ':')
			j++;
	path = (char **)ft_calloc(j + 1, sizeof(char *));
	i = 0;
	j = 0;
	while (tmp[++i])
	{
		if (tmp[i] == ':')
		{
			path[count] = ft_substr(tmp, j, i - j + 1);
			path[count++][i - j] = '/';
			j = i + 1;
		}
	}
	free(tmp);
	return (path);	
}

int				sys_path(char **arr)
{
	struct stat	sb;
	char		**path;
	char		*tmp;
	int			i;

	path = save_syspath();
	i =  -1;
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], *arr);
		if (stat(tmp, &sb) == 0)
		{
			free(*arr);
			*arr = tmp;
			ft_freearray(path);
			return (1);
		}
		free(tmp);
	}
	ft_freearray(path);
	return (0);
}

int				exec_pathfinder(char **arr)
{
	char		*tmp[2];

	if (!*arr || ft_strlen(*arr) <= 1)
		return (0);
	if (**arr == '/')
		return (1);
	if (sys_path(arr))
		return (1);
	if (*(*arr) == '.')
	{
		if (((*(*arr + 1) == '.') && (*(*arr + 2) == '/')) || (*(*arr + 1) == '/'))
			return (1); 
		return (0);
	}
	else if ((*(*arr) == '~') && (*(*arr + 1) == '/'))
	{
		tmp[0] = env_handler("HOME");
		tmp[1] = ft_strjoin(tmp[0], *arr + 1);
		free(tmp[0]);
		*arr = tmp[1];
		return (1);
	}
	return (0);
}

void			launch_exec(char **arr)
{
	int			ret;

	if ((ret = fork()) < 0)
		fork_error();
	signal(SIGINT, sighandler_c);
	if (ret == 0)
	{
		if ((execve(arr[0], arr, tmp_env) < 0))
		{
			write(2, "ERROR - EOF while looking for matching quote\n", 42);
			exit(1);
		}
		else
			exit(0);
	}
	waitpid(-1, NULL, 0);
}

void			fork_error(void)
{
	write(2, "ERROR - Fork error\n", 19);
	msh_exit();
}

void			coms_not_found(char *str)
{
	write(2, "MSH - ", 6);
	write(2, str, ft_strlen(str));
	write(2, " command not found.\n", 20);
}

void			execute_com(t_commands *table, int index)
{
	int			i[2];
	int			fd[4];
	// int			pp[2];

	i[0] = -1;
	while (++(i[0]) < index)
	{
		fd[0] = dup(0);
		fd[1] = dup(1);
		i[1] = -1;
		while ((table[i[0]].coms[++(i[1])]))
		{
			// redirect_input(table + i[0], &e);
			// redirect_output(table + i[0], &e);
			// tmp_files(tmp);
			if (coms_handler(table[i[0]].coms[i[1]]))
				pick_com_exec(table[i[0]].coms[i[1]], table + i[0]);
			else if ((exec_pathfinder(table[i[0]].coms[i[1]])))
				launch_exec(table[i[0]].coms[i[1]]);
			else if (table[i[0]].coms[i[1]][0] != NULL)
				coms_not_found(table[i[0]].coms[i[1]][0]);
		}
		reset_values(fd);
	}
	free_table(table, index);
}