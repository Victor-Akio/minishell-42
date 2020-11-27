/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:58:41 by vminomiy          #+#    #+#             */
/*   Updated: 2020/11/27 23:26:38 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Show_promtp is responsible to clear the terminal and show the ">>" that means prompt is ready to receive the input.
*/


void		show_prompt(void)
{
	char		dir_str[4096 + 1];
	char		*prompt;

	dir_str[4096] = '\0';
	getcwd(dir_str, 4096);
	// ft_putstr("\033[?1049h\033[H");
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
	t_commands	*table;

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
		if (check_empty_com(com, &input))
			continue;
		free(input);
		com = rm_empty_str(com);
		if (!(table = malloc(sizeof(t_commands) * ft_arraylen(com))))
			return (EXIT_FAILURE);
		if (!(tolken_gen(com, table, ft_arraylen(com))))
			execute_com(table, ft_arraylen(com));
	}
	return (0);
}