/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:47:31 by vminomiy          #+#    #+#             */
/*   Updated: 2020/02/14 18:16:25 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long int	ft_strlcat(char *dst, const char *src,
								unsigned long int size)
{
	unsigned long int	i;
	unsigned long int	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (1 + i + j < size && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	while (src[j] != '\0')
		j++;
	if (size < i)
		return (size + j);
	return (i + j);
}
