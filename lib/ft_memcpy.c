/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:44:43 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/14 12:53:10 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*nsrc;
	char	*ndst;

	nsrc = (char *)src;
	ndst = (char *)dst;
	i = 0;
	while (i < n && dst != src)
	{
		ndst[i] = nsrc[i];
		i++;
	}
	return (dst);
}
