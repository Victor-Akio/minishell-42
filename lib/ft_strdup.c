/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:23:44 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/01/30 16:49:05 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copstring;
	int		i;

	i = 0;
	copstring = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (copstring == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		copstring[i] = s1[i];
		i++;
	}
	copstring[i] = '\0';
	return (copstring);
}
