/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolken.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:54:26 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/25 20:36:49 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		rm_quotes_coms(t_commands *table)
{
	int			i;

	i = -1;
	while (table->coms[++i])
		rm_quotes(&table->coms[i][0]);
}

/*
** find and set the coms in the com_table
*/

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

static void		redirection_gen(t_commands *table)
{
	table->i_files = malloc(sizeof(char **) * (table->com_index + 1));
	table->i_files[table->com_index] = NULL;
	table->o_files = malloc(sizeof(char **) * (table->com_index + 1));
	table->o_files[table->com_index] = NULL;
	table->ap_files = malloc(sizeof(char **) * (table->com_index + 1));
	table->ap_files[table->com_index] = NULL;
	table->d_files = malloc(sizeof(char **) * (table->com_index + 1));
	table->d_files[table->com_index] = NULL;
}

static int		find_redirection(t_commands *table)
{
	int			i[2];
	int			count[3];

	redirection_gen(table);
	i[0] = -1;
	while (table->coms[++(*i)])
	{
		if (!(table->coms[i[0]]))
			continue ;
		count[0] = 0;
		count[1] = 0;
		count[2] = 0;
		count_redirections(table->coms[i[0]], count);
		init_redirection(table, i, count);
		if (set_redirection(table, i))
			return (1);
	}
	return (0);
}

/*
** Parser the com received to several com table.
** One for each ;
*/

int				tolken_gen(char **coms, t_commands *table, int size)
{
	int			i;
	int			j;

	i = -1;
	while (++i < size)
	{
		pick_coms(table + i, coms[i]);
		if (find_redirection(table + i))
			return (free_parser_error(table, i, coms));
		replace_env(table + i);
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
