/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:47:28 by vminomiy          #+#    #+#             */
/*   Updated: 2020/12/03 22:19:49 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*find_non_zero_char(char **ptr)
{
	char		*tmp[1];

	if ((ptr[0]) && (ptr[1]) && (ptr[2]))
	{
		*tmp = (ptr[0] < ptr[1]) ? ptr[0] : ptr[1];
		*tmp = (*tmp < ptr[2]) ? *tmp : ptr[2];
	}
	else if (!ptr[0] && (ptr[1]) && (ptr[2]))
		*tmp = (ptr[1] < ptr[2] ? ptr[1] : ptr[2]);
	else if (!ptr[1] && (ptr[0]) && (ptr[2]))
		*tmp = (ptr[0] < ptr[2]) ? ptr[0] : ptr[2];
	else if (!ptr[2] && (ptr[0]) && (ptr[1]))
		*tmp = (ptr[0] < ptr[1]) ? ptr[0] : ptr[1];
	else if ((ptr[0]) && !ptr[1] && !ptr[2])
		*tmp = ptr[0];
	else if (!ptr[0] && (ptr[1]) && !ptr[2])
		*tmp = ptr[1];
	else if (!ptr[0] && !ptr[1] && (ptr[2]))
		*tmp = ptr[2];
	else
		*tmp = 0;
	return (*tmp);
}

void			symbol_found(t_commands *table, int *i, char **ptr)
{
	char		*p1;
	int			x;
	char		*tmp;

	p1 = find_non_zero_char(ptr);
	tmp = dup_symbol(table->coms[i[0]][i[1]] + 1);
	x = ft_strlen(tmp);
	redir_files_updt(table, i, tmp, (p1 == ptr[2]) * 'A' + (p1 == ptr[0]) * 'I' + (p1 == ptr[1] )* '0');
	if (((size_t)x == ft_strlen(table->coms[i[0]][i[1]])) && (tmp))
		resize_arr_pos(&table->coms[i[0]], i[1] + 1);
	else if (tmp)
	{
		tmp = ft_strdup(table->coms[i[0]][i[1] + 1] + x);
		free(table->coms[i[0]][i[1] + 1]);
		table->coms[i[0]][i[1] + 1] = tmp;
	}
	resize_arr_pos(&table->coms[i[0]], i[1]);
}

void			word_symbol(t_commands *table, int *i, char *str, int t)
{
	int			len;

	free(str);
	str = dup_symbol(table->coms[i[0]][i[1] + 1]);
	len = ft_strlen(str);
	redir_files_updt(table, i, str, t);
	if ((size_t)len == ft_strlen(table->coms[i[0]][i[1] + 1]))
		resize_arr_pos(&table->coms[i[0]], i[1] + 1);
	else
	{
		str = ft_strdup(table->coms[i[0]][i[1] + 1] + len);
		free(table->coms[i[0]][i[1] + 1]);
		table->coms[i[0]][i[1] + 1] = str;
	}
}

void			word_redirection(t_commands *table, int *i, char **ptr)
{
	char		*p1;
	int			x;
	char		*tmp;

	p1 = find_non_zero_char(ptr);
	tmp = dup_symbol(p1 + 1);
	x = ft_strlen(tmp);
	p1 == ptr[2] ? p1[-1] = '\0' : 0;
	p1[0] = '\0';
	if ((x == 0) && !(p1[1]))
		word_symbol(table, i, tmp, (p1 == ptr[2]) * 'A'
			+ (p1 == ptr[0]) * 'I' + (p1 == ptr[1]) * 'O');
	else
	{
		redir_files_updt(table, i, tmp, (p1 == ptr[2]) * 'A'
			+ (p1 == ptr[0]) * 'I' + (p1 == ptr[1]) * 'O');
		tmp = ft_strdup(p1 + 1 + x);
		p1 = ft_strjoin(table->coms[i[0]][i[1]], tmp);
		free(table->coms[i[0]][i[1]]);
		if (tmp)
			free(tmp);
		table->coms[i[0]][i[1]] = p1;
		if (!(table->coms[i[0]][i[1]][0]))
			resize_arr_pos(&table->coms[i[0]], i[1]);
	}
}
