/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:06:41 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/12/08 17:47:59 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	msh_parser(t_msh *msh)
{
	char	*line;

	line = msh->cmd_line;

	while (*line)
	{
		ft_ignorechar(&line, ' ');
		if (!ft_strncmp((line), "echo", 4) && (ft_isspace((line)[4]) || !(line)[4]))
			return (parser_echo(&line));
		// if (!ft_strncmp((*line), "cd", 2) && (ft_isspace((*line)[2]) || !(*line)[2]))
		// 	return (parsing_cd(line, &minishell->commands));
		// if (!ft_strncmp((*line), "pwd", 3) && (ft_isspace((*line)[3]) || !(*line)[3]))
		// 	return (parsing_pwd(line, &minishell->commands));
		// if (!ft_strncmp((*line), "exit", 4) && (ft_isspace((*line)[4]) || !(*line)[4]))
		// 	return (parsing_exit(line, &minishell->commands));
		// if (!ft_strncmp((*line), "export", 6) && (ft_isspace((*line)[6]) || !(*line)[6]))
			// return (parsing_export(line, &minishell->commands));
		if (!ft_strncmp((line), "env", 4) && (ft_isspace((line)[4]) || !(line)[4]))
			parser_env(&line, msh);
		else
			line++;
		}
	return (1);
}