/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 04:47:55 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/31 23:34:24 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*env_selector(char *ev)
{
	int			len;
	char		*res;
	int			i;

	i = -1;
	while (ev[++i] && (ev[i] != ' ') && (ev[i] != '\t') && (ev[i] != '\'')
		&& (ev[i] != '"') && (ev[i] != '\n'))
		;
	len = i;
	i = 0;
	while (g_env[i] && ft_strncmp(ev, g_env[i], len) != 0)
		i++;
	if (!g_env[i] || g_env[i][len] != '=')
		res = ft_strdup("");
	else
		res = ft_substr(g_env[i], len + 1, ft_strlen(g_env[i]));
	return (res);
}

void			com_env(char **arg)
{
	int	i;

	i = -1;
	if (arg[1])
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(arg[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		errno = 127;
		return ;
	}
	while (g_env[++i])
	{
		ft_putstr(g_env[i]);
		ft_putchar(10);
	}
	errno = 0;
	return ;
}

void			save_env(int ac, char **av, char **ep)
{
	int			i;
	int			j;
	int			count;

	i = -1;
	j = -1;
	count = ft_arraylen(ep) + 1;
	(void)ac;
	(void)av;
	g_env = (char **)ft_calloc(count, sizeof(char *));
	while (ep[++j])
	{
		if ((ft_strncmp("_=", ep[j], 2) == 0) && ep[j + 1])
			j++;
		if (!(g_env[++i] = ft_strdup(ep[j])))
			msh_exit();
	}
	if (j - 1 > i && !(g_env[i + 1] = ft_strdup("_=./minishell")))
		msh_exit();
}
