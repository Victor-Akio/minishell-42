/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@students.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:22:01 by hbuisser          #+#    #+#             */
/*   Updated: 2020/08/11 06:54:54 by vminomiy         ###   ########.fr       */
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
