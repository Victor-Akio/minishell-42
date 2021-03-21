/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 04:07:44 by vminomiy          #+#    #+#             */
/*   Updated: 2021/02/14 01:42:12 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_addchar(char *str, char c)
{
	char		*res;
	int			len;
	int			i;

	i = -1;
	len = ft_strlen(str);
	res = ft_calloc(len + 2, sizeof(char));
	while (++i < len)
		res[i] = str[i];
	res[i] = c;
	free(str);
	return (res);
}
