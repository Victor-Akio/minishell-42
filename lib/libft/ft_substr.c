/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:30:00 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/16 13:05:11 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	cont;

	if (!s)
		return (NULL);
	cont = 0;
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (!substring)
		return (0);
	while (((start + cont) < ft_strlen(s)) && (cont < len))
	{
		substring[cont] = s[start + cont];
		cont++;
	}
	substring[cont] = '\0';
	return (substring);
}
