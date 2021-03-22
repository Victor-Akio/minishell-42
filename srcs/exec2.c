/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:23:01 by vminomiy          #+#    #+#             */
/*   Updated: 2021/03/21 22:09:30 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**save_syspath(void)
{
	char		*tmp;
	char		**path;
	int			count;
	int			i;
	int			j;

	reset_count(&i, &j);
	count = 0;
	tmp = env_selector("PATH");
	if (tmp[ft_strlen(tmp) - 1] != ':')
		tmp = ft_addchar(tmp, ':');
	while (tmp[++i])
		if (tmp[i] == ':')
			j++;
	path = (char **)ft_calloc(j + 1, sizeof(char *));
	reset_count(&i, &j);
	while (tmp[++i])
		if (tmp[i] == ':')
		{
			path[count] = ft_substr(tmp, j, i - j + 1);
			path[count++][i - j] = '/';
			j = i + 1;
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
			free_array(path);
			return (1);
		}
		free(tmp);
	}
	free_array(path);
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

int				launch_exec(char **arr)
{
	pid_t		pid;
	int			status;

	status = g_status;
	signal(SIGINT, sighandler_c);
	signal(SIGQUIT, sighandler_c);
	if ((pid = fork()) < 0)
		fork_error();
	else if (pid == 0)
	{
		status = execve(arr[0], arr, g_env);
	}
	else
		waitpid(pid, &status, 0);
	if (!WIFSIGNALED(status) && WIFEXITED(status))
		g_status = WEXITSTATUS(status);
	return (g_status);
}
