/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:58:21 by vminomiy          #+#    #+#             */
/*   Updated: 2021/03/20 22:53:24 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_strisdigit(char *c)
{
	size_t	i;

	i = 0;
	while (ft_isdigit(c[i]))
		i++;
	if (c[i] == '\0')
		return (1);
	return (0);
}