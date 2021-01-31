/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:30:57 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/31 02:29:40 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		*new_arg(char *arg)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = ft_calloc(ft_strlen(arg) + 3, sizeof(char));
	while (arg[i])
	{
		ret[j++] = arg[i++];
		if (arg[i - 1] == '=')
		{
			if (!arg[i])
				ret[j++] = '"';
			ret[j++] = '"';
		}
		else if (!arg[i])
			ret[j++] = '"';
	}
	ret[j] = 0;
	return (ret);
}

static char		**no_arg(void)
{
	char	**ret;
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	ret = (char **)ft_calloc(envp_len(g_env), sizeof(char *));
	while (g_env[++i] && ft_strncmp("_=", g_env[i], 2) != 0)
		ret[i] = new_arg(g_env[i]);
	i = -1;
	while (ret[++i])
	{
		j = i;
		while (ret[++j])
			if (ft_strcmp(ret[i], ret[j]) > 0)
			{
				tmp = ret[i];
				ret[i] = ret[j];
				ret[j] = tmp;
			}
	}
	return (ret);
}

static void		rep_g_env2(char *str, char **tmp, int i, int j)
{
	int		count;

	count = 0;
	while (g_env[++j])
		if (ft_strncmp(str, g_env[j], ft_findchar(str, '=') + 1))
		{
			if (!(tmp[j] = ft_strdup(str)))
				msh_exit();
			count = 1;
			break ;
		}
	if (!g_env[j])
		if (!(tmp[i] = ft_strdup(str)))
			msh_exit();
	while (g_env[i++])
	{
		if (!(tmp[i - count] = ft_strdup(g_env[i - 1])))
			msh_exit();
	}
	return ;
}

static void		rep_g_env(char *str)
{
	char	**tmp;
	char	**buffer;
	int		count;
	int		i;
	int		j;

	count = 2;
	i = -1;
	while (g_env[++i])
		if (ft_strncmp(str, g_env[i], ft_findchar(str, '=') + 1))
			count = 1;
	i = -1;
	j = -1;
	tmp = (char **)ft_calloc(envp_len(g_env) + count, sizeof(char *));
	while (g_env[++i] && ft_strncmp("_=", g_env[i], 2) != 0)
		if (!(tmp[i] = ft_strdup(g_env[i])))
			msh_exit();
	rep_g_env2(str, tmp, i, j);
	buffer = g_env;
	g_env = tmp;
	free_array(buffer);
}

void			com_export(char **arg)
{
	int		i;

	i = 0;
	errno = 0;
	if (!arg[1])
	{
		export_no_arg(no_arg());
		return ;
	}
	while (arg[++i])
	{
		if (!quote_handler(arg, i))
			return ;
		rm_quotes(arg + i);
		if (arg[i][0] == '=' || ft_strchr(arg[i], '\n'))
		{
			ft_putstr_fd("export: '", 2);
			ft_putstr_fd(arg[i], 2);
			ft_putstr_fd("': not a valid identifier.\n", 2);
			errno = 1;
		}
		else if (ft_strchr(arg[i], '='))
			rep_g_env(arg[i]);
	}
	return ;
}
