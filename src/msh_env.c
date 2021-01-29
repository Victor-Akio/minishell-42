/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 04:47:55 by vminomiy          #+#    #+#             */
/*   Updated: 2020/12/08 17:37:10 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Save_env will receive the arguments, It will save the env var in the correct position of the table.
*/

void			save_env(t_msh *msh, char **ep)
{
	int			i;
	int			j;
	int			count;

	i = -1;
	j = -1;
	count = ft_arraylen(ep) + 1;
	msh->env = (char **)ft_calloc(count, sizeof(char *));
	while (ep[++j])
	{
		if ((ft_strncmp("_=", ep[j], 2) == 0) && ep[j + 1])
			j++;
		if (!(msh->env[++i] = ft_strdup(ep[j])))
			msh_exit(msh);
	}
	if (j - 1 > i && !(msh->env[i + 1] = ft_strdup("_=./minishell")))
		msh_exit(msh);
}