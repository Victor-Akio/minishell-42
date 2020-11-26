/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:02:49 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/06 02:18:43 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t			i;
	unsigned char	*nsrc;
	unsigned char	*ndst;

	i = 0;
	nsrc = (unsigned char *)src;
	ndst = (unsigned char *)dst;
	if (dst == NULL && src == NULL)
		return (0);
	while (i < len)
	{
		*ndst = *nsrc;
		nsrc++;
		ndst++;
		if (*nsrc == (unsigned char)c)
		{
			*ndst = *nsrc;
			ndst++;
			return (ndst);
		}
		i++;
	}
	return (0);
}
