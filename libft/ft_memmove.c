/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:07:57 by vminomiy          #+#    #+#             */
/*   Updated: 2020/01/27 14:21:08 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, unsigned long int len)
{
	char				*x;
	char				*s;
	unsigned long int	i;

	x = (char *)dst;
	s = (char *)src;
	if (x < s)
	{
		i = 0;
		while (i < len)
		{
			x[i] = s[i];
			i++;
		}
	}
	else if (x > s)
	{
		i = len;
		while (i > 0)
		{
			x[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dst);
}
