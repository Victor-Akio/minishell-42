/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:57:54 by vminomiy          #+#    #+#             */
/*   Updated: 2020/01/28 13:44:54 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned long int count, unsigned long int size)
{
	void				*res;

	res = malloc(count * size);
	if (res == 0)
		return (NULL);
	ft_memset(res, 0, count * size);
	return (res);
}
