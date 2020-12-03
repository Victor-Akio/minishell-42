/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:53:18 by vminomiy          #+#    #+#             */
/*   Updated: 2020/12/03 22:01:36 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*dup_symbol(char *str)
{
	char		tmp;
	char		**quotpos;
	char		*ptr;
	char		*res;

	if (!str)
		return (0);
	quotpos = set_pos(str);
	if ((ptr = non_zero_char(ft_strquots(quotpos, str, '>'), ft_strquots(quotpos, str, '<'))))
	{
		tmp = *ptr;
		*ptr = '\0';
		res = ft_strdup(str);
		*ptr = tmp;
		rm_quotes(&str);
	}
	else
		res = ft_strdup(str);
	free(quotpos);
	return (res);
}

void			resize_arr_pos(char ***arr, int pos)
{
	int			i;
	int			j;
	int			size;
	char		**tmp;

	size = ft_arraylen(*arr);
	tmp = malloc(sizeof(char *) * (size));
	tmp[size - 1] = NULL;
	i = -1;
	j = -1;
	while (*((arr) + ++i))
	{
		if (i == pos)
			continue ;
		else
			tmp[++j] = ft_strdup(*((*arr) + i));
	}
	free_all((void **)*arr, size);
	*arr = tmp;
}

int				set_redirection(t_commands *table, int *i)
{
	char		*str;
	char		*ptr[3];
	char		**quotpos;

	i[1] = -1;
	while((str = table->coms[i[0]][++(*(i + 1))]))
	{
		quotpos = set_pos(str);
		ptr[0] = ft_strquots(quotpos, str, '<');
		ptr[1] = ft_strquots(quotpos, str, '>');
		ptr[2] = ft_strquots(quotpos, str, '>');
		free(quotpos);
		if ((ptr[0]) || (ptr[1]) || (ptr[2]))
		{
			if (((ft_strlen(str) == 1) && ((ptr[0]) || (ptr[1]))) || ((ft_strlen(str) == 2) && (ptr[2])))
				symbol_found(table, i, ptr);
			else
				word_redirection(table, i, ptr);
			if ((parser_error(table, i[0])))
				return (1);
			i[1] = -1;
		}
	}
	return (0);
}

void			count_redirections(char **arr, int *count)
{
	int			i;
	char		**quotpos;
	char		*ptr[2];

	i = -1;
	while (arr[++i])
	{
		quotpos = set_pos(arr[i]);
		ptr[1] = arr[i];
		while ((ptr[0] = ft_strquots(quotpos, ptr[1], '<')) && (ptr[1] = ptr[0] + 1))
			count[0]++;
		ptr[1] = arr[i];
		while ((ptr[0] = ft_strquots(quotpos, ptr[1], '>')) && (ptr[0][1] != '>') && (ptr[1] = ptr[0] + 1))
			count[1]++;
		ptr[1] = arr[i];
		while ((ptr[0] = ft_strquot_aux(quotpos, ptr[1], '>')) && (ptr[1] = ptr[0] + 1))
			count[2]++;
		free(quotpos);
	}
}