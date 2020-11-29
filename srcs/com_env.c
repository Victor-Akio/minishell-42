/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 10:42:43 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/29 11:04:41 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	com_env(void)
{
	int	i;

	i = -1;
	while (tmp_env[++i])
	{
		ft_putstr(tmp_env[i]);
		ft_putstr("\n");
	}
	
}
