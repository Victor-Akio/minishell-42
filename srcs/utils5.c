/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:57:53 by vminomiy          #+#    #+#             */
/*   Updated: 2021/02/08 18:56:39 by vminomiy         ###   ########.fr       */
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
		if (str[i] == c &&
			((between_quot_pair(quotpos, str + i) != -1) ||
			((j % 2) && (str + i > quotpos[j - 1]))))
			continue ;
		else if (str[i] == c)
			return (str + i);
	}
	return (0);
}

char			*ft_strquots1(char **quotpos, char *str, char c)
{
	int		i;
	int		j;

	j = ft_arraylen(quotpos);
	i = -1;
	while (str[++i])
	{
		if ((between_quot_pair(quotpos, str + i) != -1) ||
			((j % 2) && (str + i > quotpos[j - 1])))
			continue ;
		else if (!(str[i + 1]) && (str[i] == c) && (i) && (str[i - 1] != c))
			return (str + i);
		else if (!(str[i + 1]) && (i) && ((str[i] != c) || (str[i - 1] == c)))
			return (0);
		else if ((i == 0) && (str[i + 1] != c) && (str[i] == c))
			return (str + i);
		else if (i == 0)
			continue ;
		else if ((i != 0) && (str[i] == c) && (str[i + 1] != c) &&
			(str[i - 1] != c))
			return (str + i);
	}
	return (0);
}

char			*ft_strquots2(char **quotpos, char *str, char c)
{
	int			i;
	int			j;

	j = ft_arraylen(quotpos);
	i = -1;
	while ((str[++i]) && (str[i + 1]))
	{
		if ((str[i] == c) && (str[i + 1] == c) &&
			((between_quot_pair(quotpos, str + i) != -1)
			|| ((j % 2) && (str + i > quotpos[j - 1]))))
			continue ;
		else if ((str[i] == c) && (str[i + 1] == c))
			return (str + i + 1);
	}
	return (0);
}
