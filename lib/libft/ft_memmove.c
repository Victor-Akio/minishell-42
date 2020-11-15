/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:15:45 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/06 03:27:19 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*src2;
	char	*dst2;

	src2 = (char *)src;
	dst2 = dst;
	if (dst > src)
	{
		dst2 += n - 1;
		src2 += n - 1;
		while (n >= 1)
		{
			*dst2 = *src2;
			dst2--;
			src2--;
			n--;
		}
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
