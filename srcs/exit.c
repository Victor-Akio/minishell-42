/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:46:03 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/20 18:28:28 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			com_exit(void)
{
	errno = 0;
	msh_exit();
}

void			msh_exit(void)
{
	int			i;

	i = 0;
	while (tmp_env[i])
		free(tmp_env[i++]);
	free(tmp_env);
	exit(0);
}
