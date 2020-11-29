/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_envvar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 10:50:10 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/29 10:50:24 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_envvar(char *str)
{
	int		i;
	char	*tmp;

	i = -1;
	while (tmp_env[++i])
	{
		if ((tmp = ft_strnstr(tmp_env[i], str, ft_strlen(tmp_env[i]))) != 0)
			return (tmp);
	}
	return (0);
}