/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 04:03:50 by vminomiy          #+#    #+#             */
/*   Updated: 2020/11/26 19:53:02 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

/*
** msh_exit, is responsible to free the temporary var used during the process.
*/

void			msh_exit(void)
{
	int			i;

	i = 0;
	while (tmp_env[i])
		free(tmp_env[i++]);
	free(tmp_env);
	exit(0);
}

/*
** Read_input is responsible to pick each character of the input line and save.
*/

void			read_input(char **input)
{
	char		buff[1];
	int			bytes;

	while ((bytes = read(0, buff, 1)) && buff[0] != '\n')
		*input = ft_addchar(*input, buff[0]);
	*input = ft_addchar(*input, '\0');
	if (!bytes)
	{
		free(*input);
		msh_exit();
	}
}