/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:21:05 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/29 16:31:36 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	com_export(char **line)
{
	char	**res;
	char	*tmp;
	int		count;
	int		i;
	
	if ((i = find_envvar(line[1])) >= 0 )
	{
		tmp = ft_strdup(line[1]);
		free(tmp_env[i]);
		tmp_env[i] = tmp;
	}
	else
	{
		count = ft_arraylen(tmp_env);
		res = malloc(sizeof(char *) * (count + 1));
		res[count] = NULL;
		count = -1;
		i = -1;
		while (tmp_env[++i])
		{
			if (tmp_env[i][0] != '\0')
				res[++count] = ft_strdup(tmp_env[i]);
		}
		res[++count] = ft_strdup(line[1]);
		free_all((void **)tmp_env, ft_arraylen(tmp_env));
		tmp_env = res;
	}
		
}