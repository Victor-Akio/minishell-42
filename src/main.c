/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:39:25 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/26 16:41:13 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	render_hader()
{
	ft_putstr_fd(" __  __ _____ _   _ _____  _____ _    _ ______ _     \
 _        _  _ ___ \n", 1);
	ft_putstr_fd("|  \\/  |_   _| \\ | |_   _|/ ____| |  | |  ____| |  \
  | |      | || |__ \\\n", 1);
	ft_putstr_fd("| \\  / | | | |  \\| | | | | (___ | |__| | |__  | |  \
  | |      | || |_ ) |\n", 1);
	ft_putstr_fd("| |\\/| | | | | . ` | | |  \\___ \\|  __  |  __| | | \
   | |      |__   _/ /\n", 1);
	ft_putstr_fd("| |  | |_| |_| |\\  |_| |_ ____) | |  | | |____| |___\
_| |____     | |/ /_\n", 1);
	ft_putstr_fd("|_|  |_|_____|_| \\_|_____|_____/|_|  |_|______|_____\
_|______|    |_|____|\n\n", 1);
}

int			msh_prompt()
{
	render_hader();
	while (1)
	{
		t_msh	msh;
		ft_putstr_fd(" >> ", 1);
		if (!(msh.command = msh_read(&msh)))
			return (-1);
		// if (swith_command() < 0)
		// 	return (0);
	}
}

int 		main()//int argc, char **argv)
{

	msh_prompt();

	return EXIT_SUCCESS;
}