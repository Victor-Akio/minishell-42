/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:21:05 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/29 18:25:36 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	com_unset(char **line)
{
	// char	*error;
	char	**res;
	int		k;
	int		i;
	int		l;
	
	// if (!ft_isalpha(line[1]) && !ft_isdigit(line[1]) && line[1] != '_')
	// {
	// 	error = strerror(errno);
	// 	ft_putstr_fd("minishell: unset: ", STDERR_FILENO);
	// 	ft_putstr_fd(error, STDERR_FILENO);
	// 	ft_putstr_fd("\n", STDERR_FILENO);
	// }

	if ((i = find_envvar(line[1])) >= 0 )
	{
		k = ft_arraylen(tmp_env);
		res = malloc(sizeof(char *) * (k - 1));
		res[k] = NULL;
		k = 0;
		l = 0;
		while (tmp_env[k])
		{
			if (k != i)
				res[k] = ft_strdup(tmp_env[l++]);
			if (k == i)
				l++;
			k++;
		}
		free_all((void **)tmp_env, ft_arraylen(tmp_env));
		tmp_env = res;
	}
}