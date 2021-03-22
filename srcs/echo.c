/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:42:53 by vminomiy          #+#    #+#             */
/*   Updated: 2021/03/22 04:45:17 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			com_echo(char **arg)
{
	int			i;
	int			j;

	i = 1;
	if (arg[i] && ((arg[1][0] == '-' && arg[1][1] == 'n' && arg[1][2] == 0)
		|| (arg[1][0] == '"' && arg[1][3] == '"')))
		i++;
	j = i;
	while (arg[j])
		if (!quote_handler(arg, j++))
			return ;
	while (arg[i])
	{
		rm_quotes(arg + i);
		write(1, arg[i], ft_strlen(arg[i]));
		if (arg[++i])
			write(1, " ", 1);
	}
	if (arg[1] && ((arg[1][0] == '-' && arg[1][1] == 'n' && arg[1][2] == 0)
		|| (arg[1][0] == '"' && arg[1][3] == '"')))
		;
	else
		write(1, "\n", 1);
	g_status = 0;
}
