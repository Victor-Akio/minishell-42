/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:06:43 by vminomiy          #+#    #+#             */
/*   Updated: 2021/02/12 00:36:58 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			reset_count(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

void			init_redirection(t_commands *table, int *i, int *count)
{
	table->i_files[i[0]] = malloc(sizeof(char *) * ((count[0] > 0) + 1));
	table->i_files[i[0]][(count[0] > 0)] = NULL;
	if (count[0] > 0)
		table->i_files[i[0]][0] = NULL;
	table->o_files[i[0]] = malloc(sizeof(char *) * ((count[1] > 0) + 1));
	table->o_files[i[0]][(count[1] > 0)] = NULL;
	if (count[1] > 0)
		table->o_files[i[0]][0] = NULL;
	table->ap_files[i[0]] = malloc(sizeof(char *) * ((count[2] > 0) + 1));
	table->ap_files[i[0]][(count[2] > 0)] = NULL;
	if (count[2] > 0)
		table->ap_files[i[0]][0] = NULL;
	table->d_files[i[0]] = malloc(sizeof(char *) * 1);
	table->d_files[i[0]][0] = NULL;
}
