/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:28:35 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/28 15:20:43 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	com_echo(char **line)
{
	int	nl;

	nl = 1;
	(*line) += 4;
	ft_ignorechar(line, ' ');
	if (ft_strncmp((*line), "-n", 2) == 0)
	{
		nl = 0;
		(*line) += 2;
	}
	while (**line != '\0')
	{
		if (**line != '\"' && **line != '\'')
			ft_putchar_fd(**line, 1);
		(*line)++;
	}
	if (nl)
		ft_putstr_fd("\n", 1);
}