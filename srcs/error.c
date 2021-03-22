/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:01:28 by vminomiy          #+#    #+#             */
/*   Updated: 2021/03/22 15:54:43 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				coms_not_found(char *str)
{
	write(1, "MSH - ", 6);
	write(1, str, ft_strlen(str));
	write(1, " command not found.\n", 20);
	return (127);
}

void			fork_error(void)
{
	write(1, "ERROR - Fork error\n", 19);
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
