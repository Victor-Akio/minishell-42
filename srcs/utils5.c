/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 19:57:53 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/20 19:31:08 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				quot_parser(char **arg, int i)
{
	char		*ptr;
	int			ret;

	ret = 1;
	if ((ptr = non_zero_char(ft_strchr(arg[i], '"'), ft_strchr(arg[i], '\'')))
		&& !(ft_strchr(ptr + 1, *ptr)))
		ret = read_subshell(arg + i, *ptr);
	if (!ret)
		return (0);
	return (1);
}

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
		write(1, "declare -x ", 11);
		write(1, tmp[i], ft_strlen(tmp[i]));
		write(1, "\n", 1);
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
