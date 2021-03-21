/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 01:29:09 by jaqrodri          #+#    #+#             */
/*   Updated: 2021/02/14 01:29:12 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			t;

	t = count * size;
	if (!(ptr = (unsigned char *)malloc(t)))
		return (NULL);
	i = 0;
	while (i < t)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
