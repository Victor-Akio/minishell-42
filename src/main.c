/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:39:25 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/12/08 17:49:45 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int			msh_prompt(t_msh *msh)
{
	render_hader();
	while (1)
	{
		msh->path = getcwd(NULL, 0);
		ft_putstr_fd(" >> ", 1);
		if (!(msh->cmd_line = msh_read(msh)))
			return (-1);
		// if (msh_parser(msh) < 0)
			// return (0);
		msh_parser(msh);
		// if (msh_run(msh) < 0)
		// 	return (0);
	}
}

int 		main(int argc, char *argv[], char **envv)
{
	t_msh		msh;
	
	(void)argc;
	(void)argv;
	msh.cmds = NULL;
	save_env(&msh, envv);
	msh_prompt(&msh);

	return EXIT_SUCCESS;
}