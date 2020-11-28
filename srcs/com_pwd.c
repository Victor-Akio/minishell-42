/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 15:11:40 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/28 15:24:35 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	com_pwd(void)
{
	char	dir_str[4096 + 1];

	dir_str[4096] = '\0';
	getcwd(dir_str, 4096);
	write(1, dir_str, ft_strlen(dir_str));
	write(1, "\n", 1);
}
