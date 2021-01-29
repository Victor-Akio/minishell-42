/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:43:59 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/01/30 15:48:42 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*nstr1;
	unsigned char	*nstr2;

	nstr1 = (unsigned char *)str1;
	nstr2 = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (nstr1[i] != nstr2[i])
			return (nstr1[i] - nstr2[i]);
		i++;
	}
	return (0);
}
