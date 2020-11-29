/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envvar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 10:50:10 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/29 12:37:38 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_envvar(char *str, int len)
{
	int		i;
	char	*tmp;

	i = -1;
	while (tmp_env[++i])
	{
		if ((tmp = ft_strnstr(tmp_env[i], str, len)) != 0)
			return (tmp);
	}
	return (0);
}