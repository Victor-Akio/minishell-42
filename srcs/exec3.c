/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:29:01 by vminomiy          #+#    #+#             */
/*   Updated: 2020/12/03 22:17:59 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				coms_handler(char **arr)
{
	if (!arr[0])
		return (0);
	else if (!(ft_strcmp(arr[0], "echo")))
		return (1);
	else if (!(ft_strcmp(arr[0], "cd")))
		return (1);
	else if (!(ft_strcmp(arr[0], "pwd")))
		return (1);
	else if (!(ft_strcmp(arr[0], "export")))
		return (1);
	else if (!(ft_strcmp(arr[0], "unset")))
		return (1);
	else if (!(ft_strcmp(arr[0], "env")))
		return (1);
	else if (!(ft_strcmp(arr[0], "exit")))
		return (1);
	else
		return (0);
}

void			pick_com_exec(char **arr, t_commands *table)
{
	if (!(ft_strcmp(arr[0], "echo")))
		com_echo(arr);
	else if (!(ft_strcmp(arr[0], "cd")) && !((table->com_index != 1)
		&& (ft_arraylen(arr) == 1)))
		com_exit();
	else if (!(ft_strcmp(arr[0], "pwd")))
		com_exit();
	else if (!(ft_strcmp(arr[0], "export")) && (table->com_index == 1))
		com_exit();
	else if (!(ft_strcmp(arr[0], "unset")) && (table->com_index == 1))
		com_exit();
	else if (!(ft_strcmp(arr[0], "env")))
		com_exit();
	else if (!(ft_strcmp(arr[0], "exit")))
		com_exit();
}