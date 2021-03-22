/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:30:26 by vminomiy          #+#    #+#             */
/*   Updated: 2021/03/22 06:17:02 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		rep_home(char **arg)
{
	char	*tmp[2];

	tmp[0] = set_env("HOME");
	tmp[1] = ft_strjoin(tmp[0], *arg + 1);
	free(tmp[0]);
	free(*arg);
	*arg = tmp[1];
}

static int		path_error(char **arr)
{
	ft_putstr_fd("ERROR: ", 1);
	ft_putstr_fd(*arr, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd(strerror(errno), 1);
	ft_putstr_fd("\n", 1);
	g_status = 1;
	return (1);
}

char			*set_env(char *arg)
{
	int		i;
	int		len;
	char	*res;

	i = -1;
	while (arg[++i] && (arg[i] != ' ') && (arg[i] != '\t') &&
		(arg[i] != '\'') && (arg[i] != '"') && (arg[i] != '\n'))
		;
	len = i;
	i = 0;
	while (g_env[i] && ft_strncmp(arg, g_env[i], len) != 0)
		i++;
	if (!g_env[i] || g_env[i][len] != '=')
		res = ft_strdup("");
	else
		res = ft_substr(g_env[i], len + 1, ft_strlen(g_env[i]));
	return (res);
}

int				com_cd(char **arg)
{
	int		i;
	char	*path;

	path = NULL;
	if (!quote_handler(arg, 1))
		return (0);
	if (!arg[1])
	{
		path = set_env("HOME");
		i = chdir(path);
		free(path);
		if (i != 0)
			return (path_error(arg + 1));
		g_status = 0;
		return (0);
	}
	if (arg[1][0] == '~')
		rep_home(arg + 1);
	rm_quotes(arg + 1);
	i = chdir(arg[1]);
	if (i != 0)
		return (path_error(arg + 1));
	path_updt(path);
	g_status = 0;
	return (0);
}
