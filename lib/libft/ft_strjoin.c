/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:01:16 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/15 02:53:38 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sub;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	sub = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!sub)
		return (0);
	while (s1[i] != '\0')
	{
		sub[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		sub[i + j] = s2[j];
		j++;
	}
	sub[i + j] = '\0';
	return (sub);
}
