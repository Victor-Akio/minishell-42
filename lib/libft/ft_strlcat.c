/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 01:13:58 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/14 01:56:42 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	j = ft_strlen(dst);
	while (src[i] && (i + j + 1) < dstsize && dstsize > 0)
	{
		dst[i + j] = src[i];
		i++;
	}
	if ((j + i) <= dstsize)
		dst[i + j] = '\0';
	while (src[i] != '\0')
		i++;
	if (dstsize < j)
		return (dstsize + i);
	else
		return (j + i);
}
