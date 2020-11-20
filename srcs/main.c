/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:58:41 by vminomiy          #+#    #+#             */
/*   Updated: 2020/11/20 07:13:30 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void		show_prompt(void)
{
	char		dir_str[4096 + 1];
	char		*prompt;

	dir_str[4096] = '\0';
	getcwd(dir_str, 4096);
	write(1, dir_str, ft_strlen(dir_str));
	write(1, " ", 1);
	prompt = ">> ";
	write(1, prompt, 3);
	write(1, " ", 1);
}

int			main(int ac, char **av, char **ep)
{
	char		*input;
	// char		**com;
	// t_com		*com_data;

	signal(SIGQUIT, sighandler);
	save_env(ac, av, ep);
	while (1)
	{
		if (!(input = ft_calloc(1, sizeof(char))))
			return (EXIT_FAILURE);
		signal(SIGINT, sighandler);
		show_prompt();
		read_input(&input);
		//com =  separar comando com ;
		//error check
		free(input);
		// com = rm_empty_str(com);
		// if (!(com_data = malloc(sizeof(t_com) * ft_arraylen(com))))
		// 	return (EXIT_FAILURE);
	}
	return (0);
}