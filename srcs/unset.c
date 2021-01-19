/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 20:31:04 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/18 21:29:15 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		unset_parser(char *arg)
{
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(arg);
	if (ft_strchr(arg, '\n') || ft_findchar(arg, '=') != -1)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": Not a valid identifier.\n", 2);
		errno = -1;
		return (0);
	}
	i = -1;
	while (tmp_env[++i])
		if (ft_strncmp(arg, tmp_env[i], len) == 0)
			return (1);
	return (0);
}

static void		clear_tmp_env(char *arg)
{
	char	**tmp;
	char	**buffer;
	int		i;
	int		j;

	i = -1;
	j = -1;
	tmp = (char **)ft_calloc(envp_len(tmp_env), sizeof(char *));
	while (tmp_env[++i])
		if (ft_strncmp(arg, tmp_env[i], ft_findchar(tmp_env[i], '=')) != 0)
			if (!(tmp[++j] = ft_strdup(tmp_env[i])))
				msh_exit();
	buffer = tmp_env;
	tmp_env = tmp;
	free_array(buffer);
	return ;
}

void			com_unset(char **arg)
{
	int		i;

	i = 0;
	errno = 0;
	while (arg[++i])
	{
		if (!quote_handler(arg, i))
			return ;
		rm_quotes(arg + i);
		if (unset_parser(arg[i]))
			clear_tmp_env(arg[i]);
	}
	return ;
}