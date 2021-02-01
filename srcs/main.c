/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:58:41 by vminomiy          #+#    #+#             */
/*   Updated: 2021/02/01 02:33:11 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_empty_com(char **table, char **input)
{
	int		i;
	int		j;

	i = -1;
	j = ft_arraylen(table);
	while (table[++i])
	{
		if (((table[i][0] == '\0') || ft_all_spaces(table[i])) && (j != 1))
		{
			write(2, "ERROR - Syntax error.\n", 22);
			free(*input);
			*input = NULL;
			free_all((void **)table, ft_arraylen(table));
			return (1);
		}
	}
	return (0);
}

void		show_prompt(void)
{
	char		dir_str[4096 + 1];

	dir_str[4096] = '\0';
	getcwd(dir_str, 4096);
	write(1, dir_str, ft_strlen(dir_str));
	write(1, " ", 1);
	write(1, ">> ", 3);
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
		if (ft_strcmp(input, "") != 0)
		{
			com = split_quots(input, ';');
			if (check_empty_com(com, &input))
				continue;
			com = rm_empty_str(com);
			if (!(table = malloc(sizeof(t_commands) * ft_arraylen(com))))
				return (EXIT_FAILURE);
			if ((*com) && !(tolken_gen(com, table, ft_arraylen(com))))
				execute_com(table, ft_arraylen(com));
		}
		free(input);
	}
	return (0);
}
