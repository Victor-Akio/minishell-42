/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 04:21:48 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/16 12:56:46 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nn;

	nn = n;
	if (nn == -2147483648)
	{
		ft_putchar_fd(45, fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (nn < 0)
	{
		ft_putchar_fd(45, fd);
		ft_putnbr_fd(nn * (-1), fd);
	}
	else if (nn > 9)
	{
		ft_putnbr_fd(nn / 10, fd);
		ft_putnbr_fd(nn % 10, fd);
	}
	else
	{
		ft_putchar_fd(nn + '0', fd);
	}
}
