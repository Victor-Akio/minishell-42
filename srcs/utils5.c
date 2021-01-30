/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:57:53 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/30 05:16:32 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*ft_ignorechar(char **line, char c)
{
	while (**line == c)
		(*line)++;
	return (*line);
}

void			export_no_arg(char **tmp)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		ft_putstr("declare -x ");
		ft_putstr(tmp[i]);
		ft_putchar('\n');
		i++;
	}
	free_array(tmp);
}

char			*ft_strquots(char **quotpos, char *str, char c)
{
	int			i;
	int			j;

	if (!str)
		return (0);
	if (!quotpos[0])
		return (ft_strchr(str, c));
	j = ft_arraylen(quotpos);
	i = -1;
	while (str[++i])
	{
		if ((between_quot_pair(quotpos, str + i) != -1) &&
			((j % 2) && (str + i > quotpos[j - 1])))
			continue ;
		else if (str[i] == c)
			return (str + i);
	}
	return (0);
}

char			*ft_strquotsbase(char **quotpos, char *str, char c)
{
	int			i;
	int			j;

	if (!str)
		return (0);
	if (!quotpos[0])
		return (ft_strchr(str, c));
	j = ft_arraylen(quotpos);
	i = -1;
	while (str[++i])
	{
		if ((str[i] == c) && ((between_quot_pair(quotpos, str + i) != -1)
			|| ((j % 2) && (str + i > quotpos[j - 1]))))
			continue ;
		else if (str[i] == c)
			return (str + i);
	}
	return (0);
}
