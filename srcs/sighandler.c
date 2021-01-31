/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:46:50 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/31 22:46:38 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			sighandler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		show_prompt();
		signal(SIGINT, sighandler);
	}
	else if (sig == SIGQUIT)
	{
		write(1, "\n", 1);
		show_prompt();
		signal(SIGQUIT, sighandler);
	}
}

void			sighandler_c(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		signal(SIGINT, sighandler_c);
	}
	else if (sig == SIGQUIT)
	{
		write(1, "\n", 1);
		signal(SIGQUIT, sighandler_c);
	}
}
