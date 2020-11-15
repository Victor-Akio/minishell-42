/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 14:55:06 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/14 16:00:31 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isaccept(int c)
{
	return ((c >= 8 && c <= 13) || c == ' ') ? 1 : 0;
}

int			ft_atoi(const char *str)
{
	int sinal;
	int num;

	sinal = 1;
	num = 0;
	while (ft_isaccept(*str))
		str++;
	if (*str == '-')
	{
		sinal = sinal * -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sinal);
}
