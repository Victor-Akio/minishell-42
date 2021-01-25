/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:42:53 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/20 18:36:26 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				read_subshell(char **input, char c)
{
	char		buff[1];
	int			bytes;
	char		*tmp;

	*input = ft_addchar(*input, '\n');
	while ((bytes = read(0, buff, 1)) && (buff[0] != c))
		*input = ft_addchar(*input, buff[0]);
	read(0, buff, 1);
	if (!bytes)
		write(2, "ERROR - Problem to find matcher quote.\n", 39);
	else
		*input = ft_addchar(*input, c);
	if ((tmp = ft_strchr(*input, '$')))
	{
		if (((tmp - *input) != 0) && (tmp[-1] == '\\'))
			rm_backslash(input, tmp - 1);
		else
			replace_var(input, tmp - 1);
	}
	return (bytes);
}

void			com_echo(char **arg)
{
	int			i;
	int			j;

	i = 1;
	if (arg[i] && (arg[1][0] == '-' && arg[1][1] == 'n' && arg[1][2] == 0))
		i++;
	j = i;
	while (arg[j])
		if (!quot_parser(arg, j++))
			return ;
	while (arg[i])
	{
		rm_quotes(arg + i);
		write(1, arg[i], ft_strlen(arg[i]));
		if (arg[++i])
			write(1, " ", 1);
	}
	if (arg[1] && (arg[1][0] == '-' && arg[1][1] == 'n' && arg[1][2] == 0))
		;
	else
		write(1, "\n", 1);
	errno = 0;
}
