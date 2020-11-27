/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:06:41 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/26 19:16:26 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	msh_parser(t_msh *msh)
{
	char	*line;

	line = msh->command;

	while (*line)
	{
		ft_ignorechar(&line, ' ');
		if (!ft_strncmp((line), "echo", 4) && (ft_isspace((line)[4]) || !(line)[4]))
			return (parser_echo(&line));
		else
			line++;
	}
	return (1);
}