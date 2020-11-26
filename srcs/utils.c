/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 02:42:15 by vminomiy          #+#    #+#             */
/*   Updated: 2020/11/26 19:03:43 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

char			*non_zero_char(char *p1, char *p2)
{
	if (!p1 && !p2)
		return (NULL);
	else if (!p1)
		return (p2);
	else if (!p2)
		return (p1);
	else if (p1 < p2)
		return (p1);
	else
		return (p2);
}

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

void			rm_dummies(char **table)
{
	int			i;
	char		*quotpos[2];
	char		*tmp;

	i = -1;
	while (table[++i])
	{
		if ((quotpos[0] = non_zero_char(ft_strchr(table[i], '"'), ft_strchr(table[i], '\'')))
			&& (quotpos[1] = ft_strchr(quotpos[0] + 1, *quotpos[0]))
			&& (quotpos[1] - quotpos[0] == 1))
		{
			*quotpos[0] = '\0';
			*quotpos[1] = '\0';
			tmp = ft_strdup(quotpos[1] + 1);
			free(table[i]);
			table[i] = tmp;
		}
	}

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

char			**set_pos(char *str)
{
	char		*ptr;
	char		**quotpos;

	quotpos = malloc(sizeof(char *) * 1);
	*quotpos = NULL;
	while ((ptr = non_zero_char(ft_strchr(str, '"'), ft_strchr(str, '\''))))
	{
		if ((str = ft_strchr(ptr +1, *ptr)))
		{
			ft_addstr(&quotpos, ptr);
			ft_addstr(&quotpos, str);
			str++;
		}
		else
		{
			ft_addstr(&quotpos, ptr);
			break;
		}
	}
	return (quotpos);
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
		if ((between_quot_pair(quotpos, str + i) != -1)
			&& ((j % 2) && (str + i > quotpos[j -1])))
			continue;
		else if (str[i] == c)
			return (str + i);
	}
	return (0);
}

static void		table_loop(char **tab, char *str, char c, char **quotpos)
{
	int			i;
	int			j;
	char		*pos;

	i = -1;
	j = ft_arraylen(quotpos);
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
	table = malloc(sizeof(char *) * (count * 2));
	table[count + 1] = NULL;
	table_loop(table, str, c, quotpos);
	rm_dummies(table);
	free(quotpos);
	return (table);
}

void			free_all(void **buff, int len)
{
	int		i;

	if (buff)
	{
		i = -1;
		while (++i < len && buff[i])
		{
			if (buff[i])
				free(buff[i]);
		}
		free(buff);
	}
}

char			**rm_empty_str(char **arr)
{
	int		i;
	int		count;
	char	**res;

	count = 0;
	i = -1;
	while (arr[++i])
	{
		if (arr[i][0] != '\0')
			count++;
	}
	res = malloc(sizeof(char *) * (count + 1));
	res[count] = NULL;
	count = -1;
	i = -1;
	while (arr[++i])
	{
		if (arr[i][0] != '\0')
			res[++count] = ft_strdup(arr[i]);
	}
	free_all((void **)arr, ft_arraylen(arr));
	arr = res;
	return (arr);
}