/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 00:34:50 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/26 00:37:05 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*msh_read(t_msh *msh)
{
	if (!(msh->command = ft_strdup("")))
		return (NULL);
	if (get_next_line(STDIN_FILENO, &msh->command) == -1)
		return(NULL);
	printf("%s\n", msh->command);
	return (msh->command);
}