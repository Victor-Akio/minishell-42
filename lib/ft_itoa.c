/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 01:58:44 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/16 13:34:17 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cont_num(int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	if (n < 0)
	{
		i++;
		nb = n * (-1);
	}
	else
		nb = n;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char			*s;
	int				num;
	unsigned int	nb;

	num = cont_num(n);
	s = (char *)malloc((num + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	if (n == 0)
		return (ft_substr("0", 0, 1));
	if (n < 0)
	{
		s[0] = '-';
		nb = n * (-1);
	}
	else
		nb = n;
	s[num--] = '\0';
	while (num > 0 || nb > 0)
	{
		s[num] = (nb % 10) + '0';
		nb = nb / 10;
		num--;
	}
	return (s);
}
