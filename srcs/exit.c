/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:46:03 by vminomiy          #+#    #+#             */
/*   Updated: 2021/03/20 23:06:12 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			exit_arg(int err)
{
	int			i;

	i = 0;
	while (g_env[i])
		free(g_env[i++]);
	free(g_env);
	exit(err);
}

void			com_exit(char **arr)
{
	int		i;

	i = 0;
	while (i++ <= ft_arraylen(arr))
	{
		if (arr[0] && !arr[1])
		{
			g_status = 0;
			msh_exit();
		}
		else if (arr[i] && ft_strisdigit(arr[i]))
		{
			ft_putstr_fd("exit\n", 1);
			ft_putstr_fd("error: exit: too many arguments\n", 1);
			g_status = 1;
			break ;
		}
		else if (arr[i])
		{
			ft_putstr_fd("exit\nERROR: Exit: ", 1);
			ft_putstr_fd(arr[2], 1);
			ft_putstr_fd(": numeric argument required\n", 1);
			exit_arg(2);
		}
	}
}

void			msh_exit(void)
{
	int			i;

	i = 0;
	while (g_env[i])
		free(g_env[i++]);
	free(g_env);
	exit(0);
}
