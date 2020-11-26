/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:58:41 by vminomiy          #+#    #+#             */
/*   Updated: 2020/11/26 20:06:50 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

/*
** Show_promtp is responsible to clear the terminal and show the ">>" that means prompt is ready to receive the input.
*/


void		show_prompt(void)
{
	char		dir_str[4096 + 1];
	char		*prompt;

	dir_str[4096] = '\0';
	getcwd(dir_str, 4096);
	ft_putstr("\033[?1049h\033[H");
	write(1, dir_str, ft_strlen(dir_str));
	write(1, " ", 1);
	prompt = ">> ";
	write(1, prompt, 3);
	write(1, " ", 1);
}

int			main(int ac, char **av, char **ep)
{
	char		*input;
	char		**com;

	signal(SIGQUIT, sighandler);
	save_env(ac, av, ep);
	while (1)
	{
		if (!(input = ft_calloc(1, sizeof(char))))
			return (EXIT_FAILURE);
		signal(SIGINT, sighandler);
		show_prompt();
		read_input(&input);
		com = split_quots(input, ';');
		free(input);
	}
	return (0);
}