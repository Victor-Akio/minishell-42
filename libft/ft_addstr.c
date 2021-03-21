/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 04:07:44 by vminomiy          #+#    #+#             */
/*   Updated: 2021/02/14 01:23:26 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_addstr(char ***arr, char *str)
{
	char		**tmp;
	int			len;
	int			i;

	len = ft_arraylen(*arr);
	tmp = malloc(sizeof(char *) * (len + 2));
	tmp[len + 1] = NULL;
	tmp[len] = str;
	i = -1;
	while (*(*arr + ++i))
		tmp[i] = *(*arr + i);
	free(*arr);
	*arr = tmp;
}
