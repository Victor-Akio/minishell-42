/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:28:35 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/12/08 17:47:29 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*msh_getword(char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (!msh_isseparator(line[0][i]))
		i++;
	if (*line)
	{
		tmp = ft_substr(*line, 0, i);
		*line += i;
	}
	return (tmp);
}

int			parser_env(char **line, t_msh *msh)
{
	char	*cmd;
	char	*data;
	
	cmd = msh_getword(line);
	ft_ignorechar(line, ' ');
	data = msh_getword(line);
	msh->cmds = lcmd_new(msh->cmds, cmd, data, 0, 1);
	return ();
}