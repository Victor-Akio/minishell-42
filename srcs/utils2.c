/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:53:18 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/31 21:36:44 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			**set_pos(char *str)
{
	char		*ptr;
	char		**quotpos;

	quotpos = malloc(sizeof(char *) * 1);
	*quotpos = NULL;
	while ((ptr = non_zero_char(ft_strchr(str, '"'), ft_strchr(str, '\''))))
	{
		if ((str = ft_strchr(ptr + 1, *ptr)))
		{
			ft_addstr(&quotpos, ptr);
			ft_addstr(&quotpos, str);
			str++;
		}
		else
		{
			ft_addstr(&quotpos, ptr);
			break ;
		}
	}
	return (quotpos);
}

char			*dup_symbol(char *str)
{
	char		tmp;
	char		**quotpos;
	char		*ptr;
	char		*res;

	if (!str)
		return (0);
	quotpos = set_pos(str);
	if ((ptr = non_zero_char(ft_strquots(quotpos, str, '>'),
		ft_strquots(quotpos, str, '<'))))
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
		while ((ptr[0] = ft_strquots(quotpos, ptr[1], '<')) &&
			(ptr[1] = ptr[0] + 1))
			count[0]++;
		ptr[1] = arr[i];
		while ((ptr[0] = ft_strquots(quotpos, ptr[1], '>')) &&
			(ptr[0][1] != '>') && (ptr[1] = ptr[0] + 1))
			count[1]++;
		ptr[1] = arr[i];
		while ((ptr[0] = ft_strquots1(quotpos, ptr[1], '>')) &&
			(ptr[1] = ptr[0] + 1))
			count[2]++;
		free(quotpos);
	}
}
