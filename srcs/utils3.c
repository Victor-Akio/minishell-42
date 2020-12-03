/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:01:31 by vminomiy          #+#    #+#             */
/*   Updated: 2020/12/03 21:02:49 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			count_redirection(char **arr, int *count)
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

int				check_empty_com(char **table, char **input)
{
	int			i;
	int			j;

	i = -1;
	j = ft_arraylen(table);
	while (table[++i])
	{
		if (((table[i][0] == '\0') || ft_all_spaces(table[i])) && (j != 1))
		{
			write (2, "ERROR - Syntax error.\n", 22);
			free(input);
			*input = NULL;
			free_all((void **)table, ft_arraylen(table));
			return (1);
		}
	}
	return (0);
}

char			*ft_strquot_aux(char **quotpos, char *str, char c)
{
	int			i;
	int			x;

	x = ft_arraylen(quotpos);
	i = -1;
	while ((str[++i]) && (str[i + 1]))
	{
		if ((str[i] == c) && (str[i + 1] == c) && ((between_quot_pair(quotpos, str + i) != -1)
			|| ((x % 2) && (str + i > quotpos[x - 1]))))
			continue ;
		else if ((str[i] == c) && (str[i + 1] == c))
			return (str + i + 1);
	}
	return (0);
}