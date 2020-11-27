/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 04:47:55 by vminomiy          #+#    #+#             */
/*   Updated: 2020/11/26 20:50:31 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Save_env will receive the arguments, It will save the env var in the correct position of the table.
*/

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
	tmp_env = (char **)ft_calloc(count, sizeof(char *));
	while (ep[++j])
	{
		if ((ft_strncmp("_=", ep[j], 2) == 0) && ep[j + 1])
			j++;
		if (!(tmp_env[++i] = ft_strdup(ep[j])))
			msh_exit();
	}
	if (j - 1 > i && !(tmp_env[i + 1] = ft_strdup("_=./minishell")))
		msh_exit();
}