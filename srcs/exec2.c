/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:23:01 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/30 05:38:24 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**save_syspath(void)
{
	char		*tmp;
	char		**path;
	t_var		var;

	var = reset_count();
	tmp = env_selector("PATH");
	if (tmp[ft_strlen(tmp) - 1] != ':')
		tmp = ft_addchar(tmp, ':');
	while (tmp[++var.i])
		if (tmp[var.i] == ':')
			var.j++;
	path = (char **)ft_calloc(var.j + 1, sizeof(char *));
	reset_count();
	while (tmp[++var.i])
	{
		if (tmp[var.i] == ':')
		{
			path[var.count] = ft_substr(tmp, var.j, var.i - var.j + 1);
			path[var.count++][var.i - var.j] = '/';
			var.j = var.i + 1;
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
	i = -1;
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
		if (((*(*arr + 1) == '.') && (*(*arr + 2) == '/')) ||
			(*(*arr + 1) == '/'))
			return (1);
		return (0);
	}
	else if ((*(*arr) == '~') && (*(*arr + 1) == '/'))
	{
		tmp[0] = env_selector("HOME");
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
