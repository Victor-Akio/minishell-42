/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:07:48 by vminomiy          #+#    #+#             */
/*   Updated: 2020/12/03 20:21:34 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		dummy_update(t_commands *table, int *i, char *str, int index)
{
	int			j;
	char		**tmp;

	tmp = malloc(sizeof(char *) * (ft_arraylen(table->d_files[i[0]]) + 2));
	tmp[ft_arraylen(table->d_files[i[0]]) + 1] = NULL;
	j = -1;
	while (table->d_files[i[0]][++j])
		tmp[j] = ft_strdup(table->d_files[i[0]][j]);
	if ((table->o_files[i[0]][0]))
	{
		tmp[j] = ft_strdup(table->o_files[i[0]][0]);
		free(table->o_files[i[0]][0]);
		table->o_files[i[0]][0] = NULL;
	}
	if ((table->ap_files[i[0]][0]))
	{
		tmp[j] = ft_strdup(table->ap_files[i[0]][0]);
		free(table->ap_files[i[0]][0]);
		table->ap_files[i[0]][0] = NULL;
	}
	index == '0' ? table->o_files[i[0]][0] = ft_strdup(str) : 0;
	index == 'A' ? table->ap_files[i[0]][0] = ft_strdup(str) : 0;
	ft_freearray(table->d_files[i[0]]);
	table->d_files[i[0]] = tmp;
}

void			redir_files_updt(t_commands *table, int *i, char *str, int index)
{
	if (!str)
		str = ft_calloc(1, sizeof(char));
	if ((index == 'A') && (!(table->o_files[i[0]][0])
		&& !(table->ap_files[i[0]][0])))
		table->ap_files[i[0]][0] = ft_strdup(str);
	else if ((index == 'O') && (!(table->o_files[i[0]][0])
		&& !(table->ap_files[i[0]][0])))
		table->o_files[i[0]][0] = ft_strdup(str);
	else if (((index == 'O') || (index == 'A')) && ((table->o_files[i[0]][0])
		|| (table->ap_files[i[0]][0])))
		dummy_update(table, i, str, index);
	else if ((index == 'I') && !(table->i_files[i[0]][0]))
		table->i_files[i[0]][0] = ft_strdup(str);
	else if ((index == 'I') && ((table->i_files[i[0]][0])))
	{
		free(table->i_files[i[0]][0]);
		table->i_files[i[0]][0] = ft_strdup(str);
	}
	free(str);
}