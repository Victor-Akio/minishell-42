/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 02:54:31 by vminomiy          #+#    #+#             */
/*   Updated: 2020/02/15 04:31:40 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*strtok(char *str, const char *sep)
{
	static char *aux = NULL;

	if (str)
		aux = str;
	if (!aux)
		return (NULL);
	while (*aux && ft_strchr(sep, *aux))
		aux++;
	while (aux && !ft_strchr(sep, *aux))
		aux++;
	if (!*aux)
		return (NULL);
	return (aux);
}
