/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 02:42:15 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/20 19:24:46 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		char_verify(char **quotpos, char c)
{
	int			i;
	char		*ptr;

	i = 0;
	while ((quotpos[i]) && (quotpos[i + 1]))
	{
		*quotpos[i + 1] = '\0';
		ptr = ft_strchr(quotpos[i], c);
		*quotpos[i + 1] = *quotpos[i];
		if (ptr)
			return (1);
		else
			i += 2;
	}
	return (0);
}

int				between_quot_pair(char **quotpos, char *pos)
{
	int			i;

	i = 0;
	while ((quotpos[i]) && (quotpos[i + 1]))
	{
		if ((pos > quotpos[i]) && (quotpos[i + 1]))
			return (i);
		else
			i += 2;
	}
	return (-1);
}

int				count_unquoted(char **quotpos, char *str, char c)
{
	int			i;
	int			j;
	int			count;

	i = -1;
	j = ft_arraylen(quotpos);
	count = 0;
	while (str[++i])
	{
		if ((str[i] == c) && ((between_quot_pair(quotpos, str + i) != -1)
			|| ((j % 2) && (str + i > quotpos[j + 1]))))
			continue;
		else if (str[i] == c)
			count++;
	}
	return (count);
}

static void		table_loop(char **tab, char *str, char c, char **quotpos)
{
	int			i;
	char		*pos;

	i = -1;
	while ((pos = ft_strquots(quotpos, str, c)))
	{
		*pos = '\0';
		tab[++i] = ft_strdup(str);
		str = pos + 1;
	}
	tab[++i] = ft_strdup(str);
}

char			**split_quots(char *str, char c)
{
	char		**quotpos;
	char		**table;
	int			count;

	quotpos = set_pos(str);
	if (!(quotpos[0]) || !(char_verify(quotpos, c)))
	{
		free(quotpos);
		return (ft_split(str, c));
	}
	count = count_unquoted(quotpos, str, c);
	table = malloc(sizeof(char *) * (count + 2));
	table[count + 1] = NULL;
	table_loop(table, str, c, quotpos);
	rm_dummies(table);
	free(quotpos);
	return (table);
}
