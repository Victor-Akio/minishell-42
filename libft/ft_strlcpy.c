/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:33:18 by vminomiy          #+#    #+#             */
/*   Updated: 2020/01/28 14:00:23 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (src != NULL)
	{
		while (src[i])
		{
			i++;
		}
		while (size != 0 && j < (size - 1) && src[j])
		{
			dst[j] = src[j];
			j++;
		}
		if (size != 0)
			dst[j] = '\0';
		return (i);
	}
	return (0);
}
