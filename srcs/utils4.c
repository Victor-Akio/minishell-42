/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:37:59 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/18 20:06:59 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			input_minishell(char **input, char c)
{
	char		buffer[1];
	int			bytes;
	char		*tmp;

	*input = ft_addchar(*input, '\n');
	while ((bytes = read(0, buffer, 1)) && (buffer[0] != c))
		*input = ft_addchar(*input, buffer[0]);
	read(0, buffer, 1);
	if (!bytes)
		ft_putstr_fd("minishell: EOF while looking for matching quote\n", 2);
	else
		*input = ft_addchar(*input, c);
	if ((tmp = ft_strchr(*input, '$')))
	{
		if (((tmp - *input) != 0) && (tmp[-1] == '\\'))
			rm_backslash(input, tmp - 1);
		else
			replace_var(input, tmp + 1);
	}
	return (bytes);
}