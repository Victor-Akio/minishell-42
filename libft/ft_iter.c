/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 02:27:27 by vminomiy          #+#    #+#             */
/*   Updated: 2020/02/15 02:33:03 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_first(char *str, char c, int pos)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	if (i == pos)
		return (1);
	return (0);
}

static int		is_instring(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (1);
}

void			ft_inter(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (is_first(s1, s1[i], i) && is_instring(s2, s1[i]))
			write(1, &s1[i], 1);
		i++;
	}
}
