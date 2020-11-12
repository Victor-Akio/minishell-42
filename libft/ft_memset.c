/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:20:55 by vminomiy          #+#    #+#             */
/*   Updated: 2020/01/27 19:08:45 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, unsigned long int len)
{
	unsigned long int	i;
	unsigned char		*b2;

	b2 = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*b2 = (unsigned char)c;
		i++;
		b2++;
	}
	return (b);
}
