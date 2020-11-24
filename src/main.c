/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:39:25 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/19 23:37:46 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void msh_loop(void)
{
	char *line;
	// char **args;
	// int status;

	// status = 1;
	ft_putstr_fd("  __  __ _____ _   _ _____  _____ _    _ ______ _      _        _  _ ___ \n |  \\/  |_   _| \\ | |_   _|/ ____| |  | |  ____| |    | |      | || |__ \\\n | \\  / | | | |  \\| | | | | (___ | |__| | |__  | |    | |      | || |_ ) |\n | |\\/| | | | | . ` | | |  \\___ \\|  __  |  __| | |    | |      |__   _/ /\n | |  | |_| |_| |\\  |_| |_ ____) | |  | | |____| |____| |____     | |/ /_\n |_|  |_|_____|_| \\_|_____|_____/|_|  |_|______|______|______|    |_|____|\n\n", 1);
	while (1){
	

	ft_putstr_fd("  >> ", 1);
	line = msh_getline();
	// if ((line = msh_getline()) != NULL)
	// 	break;
	// args = lsh_split_line(line);
	// status = lsh_execute(args);
	free(line);
	// free(args);
	} 
}

int main()//int argc, char **argv)
{

	msh_loop();

	return EXIT_SUCCESS;
}