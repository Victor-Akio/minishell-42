/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 21:40:40 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/26 00:36:11 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

# include <stdio.h>

typedef struct	s_msh
{
	char		*command;
}				t_msh;

void	ft_strdel(char **str);
char	*msh_read(t_msh *msh);




#endif
