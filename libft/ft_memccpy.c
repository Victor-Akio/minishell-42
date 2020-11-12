/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 06:49:42 by vminomiy          #+#    #+#             */
/*   Updated: 2020/01/27 14:25:14 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, unsigned long int n)
{
	unsigned char		*dst1;
	unsigned char		*src1;
	unsigned long int	i;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst1[i] = src1[i];
		if (dst1[i] == (unsigned char)c)
			return ((void *)(dst1 + i + 1));
		i++;
	}
	return (NULL);
}
