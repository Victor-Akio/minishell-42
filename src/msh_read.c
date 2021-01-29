/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 00:34:50 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/30 17:54:41 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*msh_read(t_msh *msh)
{
	if (!(msh->cmd_line = ft_strdup("")))
		return (NULL);
	if (get_next_line(STDIN_FILENO, &msh->cmd_line) == -1)
		return(NULL);
	// printf("%s\n", msh->cmd_line);
	return (msh->cmd_line);
}