/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:27:15 by vminomiy          #+#    #+#             */
/*   Updated: 2020/02/13 13:42:57 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	str[i] = ft_toupper(str[i]);
	while (str[++i])
	{
		str[i] = ft_tolower(str[i]);
		if (!ft_isalnum(str[i - 1]))
			str[i] = ft_toupper(str[i]);
	}
	return (str);
}
