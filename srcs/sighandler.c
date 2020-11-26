/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:46:50 by vminomiy          #+#    #+#             */
/*   Updated: 2020/11/26 20:07:49 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

/*
** Sighandler will be the parent handler
*/

void			sighandler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		//show_prompt();
		signal(SIGINT, sighandler);

	}
}

/*
** Sighandler C is the children handler.
*/

void			sighandler_c(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		signal(SIGINT, sighandler_c);
	}
}