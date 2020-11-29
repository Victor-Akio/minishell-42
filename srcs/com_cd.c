/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 18:31:51 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/29 10:50:21 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	com_cd(char **line)
{
	char	*error;

	if (!ft_strcmp(line[1], ""))
	{
		line[1] = ft_strdup(find_envvar("HOME"));
	}
	errno = 0;
	if (chdir(line[1]) < 0)
	{
		error = strerror(errno);
		ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
		ft_putstr_fd(error, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
}