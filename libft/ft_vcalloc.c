/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vcalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:09:40 by vminomiy          #+#    #+#             */
/*   Updated: 2021/02/14 01:59:18 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					*ft_vcalloc(size_t count, int value)
{
	size_t		i;
	int			*mem;

	i = 0;
	if (!(mem = (int*)malloc(count * sizeof(int))))
		return (NULL);
	while (i < count)
	{
		mem[i] = value;
		i++;
	}
	return (mem);
}
