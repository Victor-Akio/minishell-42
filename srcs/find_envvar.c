/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_envvar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 10:50:10 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/29 17:43:42 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		find_envvar(char *str)
{
	int		i;
	int		j;

	i = -1;
	while (tmp_env[++i])
	{
		j = 0;
		while (tmp_env[i][j] == str[j])
			j++;
		// j--;
		if (tmp_env[i][j] == '=' && (int)ft_strlen(str) == j)
			return (i);
	}
	return (-1);
}