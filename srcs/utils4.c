/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:37:59 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/19 19:56:01 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void			rm_dummies(char **table)
{
	int			i;
	char		*quotpos[2];
	char		*tmp;

	i = 0;
	while (table[i])
	{
		if ((quotpos[0] = non_zero_char(ft_strchr(table[i], '"'), ft_strchr(table[i], '\'')))
			&& (quotpos[1] = ft_strchr(quotpos[0] + 1, *quotpos[0]))
			&& ((quotpos[1] - quotpos[0]) == 1))
		{
			*quotpos[0] = '\0';
			*quotpos[1] = '\0';
			tmp = ft_strdup(quotpos[1] + 1);
			free(table[i]);
			table[i] = tmp;
		}
		i++;
	}
}

char			*non_zero_char(char *p1, char *p2)
{
	if (!p1 && !p2)
		return (NULL);
	else if (!p1)
		return (p2);
	else if (!p2)
		return (p1);
	else
		return ((p1 < p2) ? p1 : p2);
}

int			input_minishell(char **input, char c)
{
	char		buffer[1];
	int			bytes;
	char		*tmp;

	*input = ft_addchar(*input, '\n');
	while ((bytes = read(0, buffer, 1)) && (buffer[0] != c))
		*input = ft_addchar(*input, buffer[0]);
	read(0, buffer, 1);
	if (!bytes)
		ft_putstr_fd("minishell: EOF while looking for matching quote\n", 2);
	else
		*input = ft_addchar(*input, c);
	if ((tmp = ft_strchr(*input, '$')))
	{
		if (((tmp - *input) != 0) && (tmp[-1] == '\\'))
			rm_backslash(input, tmp - 1);
		else
			replace_var(input, tmp + 1);
	}
	return (bytes);
}

void			rm_quotes(char **arr)
{
	int			i;
	char		*quotpos[2];
	char		*tmp;

	i = -1;
	if (!*arr)
		return ;
	while (*(*arr + ++i))
	{
		if ((quotpos[0] = non_zero_char(ft_strchr(*arr, '"'),
			ft_strchr(*arr, '\''))) && (quotpos[1] = ft_strchr(quotpos[0] + 1,
			*quotpos[0])))
		{
			*quotpos[0] = '\0';
			*quotpos[1] = '\0';
			tmp = ft_strjoin(*arr, quotpos[0] + 1);
			free(*arr);
			*arr = tmp;
		}
	}
}
