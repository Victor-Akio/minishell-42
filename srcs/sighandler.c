/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:46:50 by vminomiy          #+#    #+#             */
/*   Updated: 2021/03/19 22:57:05 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			sighandler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		show_prompt();
		g_status = 130;
	}
	else if (sig == SIGQUIT)
	{
		ft_putstr_fd("\b \b\b \b", 1);
	}
}

void			sighandler_c(int sig)
{
	write(1, "\n", 1);
	if (sig == SIGINT)
		g_status = 130;
	else if (sig == SIGQUIT)
		g_status = 131;
}
