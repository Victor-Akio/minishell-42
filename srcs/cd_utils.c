/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 04:51:26 by vminomiy          #+#    #+#             */
/*   Updated: 2021/03/22 07:36:44 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		change_env(char **ev, char *prefix, char *path)
{
	char	*tmp;

	tmp = ft_strjoin(prefix, path);
	free(*ev);
	*ev = tmp;
}

static void	init_tmp(char **tmp, int *i)
{
	*i = -1;
	tmp[0] = NULL;
	tmp[1] = NULL;
}

void		path_updt(char *path)
{
	char	buffer[4096 + 1];
	int		i;
	char	*tmp[2];

	init_tmp(&tmp[0], &i);
	buffer[4096] = '\0';
	path = getcwd(buffer, 4096);
	while (g_env[++i])
		if (ft_strnstr(g_env[i], "OLDPWD=", ft_strlen(g_env[i])))
			tmp[1] = ft_substr(g_env[i], 7, ft_strlen(g_env[i]));
		else if (ft_strnstr(g_env[i], "PWD=", ft_strlen(g_env[i])))
			tmp[0] = ft_substr(g_env[i], 4, ft_strlen(g_env[i]));
	free(tmp[1]);
	tmp[1] = ft_substr(tmp[0], 0, ft_strlen(tmp[0]));
	free(tmp[0]);
	tmp[0] = ft_substr(path, 0, ft_strlen(path));
	i = -1;
	while (g_env[++i])
		if (ft_strnstr(g_env[i], "OLDPWD=", ft_strlen(g_env[i])))
			change_env(&g_env[i], "OLDPWD=", tmp[1]);
		else if (ft_strnstr(g_env[i], "PWD=", ft_strlen(g_env[i])))
			change_env(&g_env[i], "PWD=", tmp[0]);
	free(tmp[0]);
	free(tmp[1]);
}
