/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:01:28 by vminomiy          #+#    #+#             */
/*   Updated: 2020/12/03 20:19:09 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			coms_not_found(char *str)
{
	write(2, "MSH - ", 6);
	write(2, str, ft_strlen(str));
	write(2, " command not found.\n", 20);
}

void			fork_error(void)
{
	write(2, "ERROR - Fork error\n", 19);
	msh_exit();
}

int				parser_error(t_commands *table, int i)
{
	if (((table->i_files[i][0]) && !(table->i_files[i][0][0]))
		|| ((table->o_files[i][0]) && !(table->o_files[i][0][0]))
		|| ((table->ap_files[i][0]) && !(table->ap_files[i][0][0])))
		return (1);
	else
		return (0);
}