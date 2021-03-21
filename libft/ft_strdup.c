/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:54:45 by vminomiy          #+#    #+#             */
/*   Updated: 2020/12/03 19:33:57 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		size;

	size = ft_strlen(s1);
	if (!(s2 = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (*((char *)s1 + i))
	{
		s2[i] = *((char *)s1 + i);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
