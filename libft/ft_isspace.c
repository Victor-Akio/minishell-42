/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 09:24:42 by vminomiy          #+#    #+#             */
/*   Updated: 2021/02/14 01:29:51 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_isspace_nl(int c)
{
	return ((c == '\t') || (c == '\v') || (c == '\f')
		|| (c == '\r') || (c == ' '));
}

int				ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int				ft_arespace(char *line)
{
	size_t	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '\0')
		return (1);
	return (0);
}
