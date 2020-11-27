/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:47:28 by vminomiy          #+#    #+#             */
/*   Updated: 2020/11/27 23:48:29 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_all_spaces(char *str)
{
	int			i;
	int			j;

	i = -1;
	j = ft_strlen(str);
	while ((++i < j) && (ft_isspace(str[i]) && str[i] != '\n'))
		;
	if (i == j)
		return (1);
	else
		return (0);
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

static void		rm_quotes_coms(t_commands *table)
{
	int			i;

	i = -1;
	while (table->coms[++i])
		rm_quotes(&table->coms[i][0]);
}

static void		pick_coms(t_commands *table, char *coms)
{
	char		**quotpos;
	int			count;
	int			i;
	char		*tmp;

	quotpos = set_pos(coms);
	count = count_unquoted(quotpos, coms, '|');
	table->com_index = count + 1;
	if (!(table->coms = malloc(sizeof(char **) * (table->com_index + 1))))
		msh_exit();
	table->coms[table->com_index] = NULL;
	i = -1;
	tmp = coms;
	while ((tmp = ft_strquots(quotpos, coms, '|')))
	{
		*tmp = '\0';
		table->coms[++i] = rm_empty_str(split_quots(coms, ' '));
		coms = tmp + 1;
	}
	table->coms[++i] = rm_empty_str(split_quots(coms, ' '));
	rm_quotes_coms(table);
	free(quotpos);
}

int				free_parser_error(t_commands *table, int index, char **coms)
{
	int			i;
	int			j;

	write(2, "ERROR - parse error.\n", 21);
	free_all((void **)coms, ft_arraylen(coms));
	i = -1;
	while (++i <= index)
	{
		j = -1;
		while (++j < table[i].com_index)
		{
			ft_freearray(table[i].coms[j]);
			// ft_freearray(table[i].i_files[j]);
			// ft_freearray(table[i].o_files[j]);
			// ft_freearray(table[i].ap_files[j]);
			// ft_freearray(table[i].d_files[j]);
		}
		free_ptrs(table + i);
	}
	free(table);
	return (1);
}

int				tolken_gen(char **coms, t_commands *table, int size)
{
	int			i;
	int			j;

	i = -1;
	while (++i < size)
	{
		pick_coms(table + i, coms[i]);
		// if (find_redirection(table + i))
		// 	return (free_parser_error(table, i, coms));
		j = -1;
		while (table[i].coms[++j])
		{
			if ((table[i].coms[j][0] == NULL) && (table[i].com_index > 1))
				return (free_parser_error(table, i, coms));
		}
	}
	ft_freearray(coms);
	return (0);
}
