/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 20:18:20 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/31 02:21:38 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		com_pwd(char **arg)
{
	char	buffer[4096 + 1];

	buffer[4096] = '\0';
	(void)arg;
	getcwd(buffer, 4096);
	ft_putstr(buffer);
	ft_putstr("\n");
	errno = 0;
	return ;
}
