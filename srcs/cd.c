/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:30:26 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/19 19:22:30 by vminomiy         ###   ########.fr       */
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
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(*arr, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	errno = 1;
	return (1);
}

char			*set_env(char *arg)
{
	int		i;
	int		len;
	char	*res;

	i = -1;
	while (arg[++i] && (arg[i] != ' ') && (arg[i] != '\t') && (arg[i] != '\'') &&
		(arg[i] != '"') && (arg[i] != '\n'))
		;
	len = i;
	i = 0;
	while (tmp_env[i] && ft_strncmp(arg, tmp_env[i], len) != 0)
		i++;
	if (!tmp_env[i] || tmp_env[i][len] != '=')
		res = ft_strdup("");
	else
		res = ft_substr(tmp_env[i], len + 1, ft_strlen(tmp_env[i]));
	return (res);
}

int				com_cd(char **arg)
{
	int		i;
	char	*path;

	if (!quote_handler(arg, 1))
		return (0);
	if (!arg[1])
	{
		path = set_env("HOME");
		i = chdir(path);
		free(path);
		if (i != 0)
			return (path_error(arg + 1));
		errno = 0;
		return (0);
	}
	if (arg[1][0] == '~')
		rep_home(arg + 1);
	rm_quotes(arg + 1);
	i = chdir(arg[1]);
	if (i != 0)
		return (path_error(arg + 1));
	errno = 0;
	return (0);
}