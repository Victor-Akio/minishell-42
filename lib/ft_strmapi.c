/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 00:50:44 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/15 17:45:27 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ms;

	if (!s || !f)
		return (NULL);
	i = 0;
	ms = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (ms == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		ms[i] = f(i, s[i]);
		i++;
	}
	ms[i] = '\0';
	return (ms);
}
