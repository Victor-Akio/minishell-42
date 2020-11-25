/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 02:42:15 by vminomiy          #+#    #+#             */
/*   Updated: 2020/11/25 18:47:50 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh.h"

void		free_all(void **buff, int len)
{
	int		i;

	if (buff)
	{
		i = -1;
		while (++i < len && buff[i])
		{
			if (buff[i])
				free(buff[i]);
		}
		free(buff);
	}
}

char		**rm_empty_str(char **arr)
{
	int		i;
	int		count;
	char	**res;

	count = 0;
	i = -1;
	while (arr[++i])
	{
		if (arr[i][0] != '\0')
			count++;
	}
	res = malloc(sizeof(char *) * (count + 1));
	res[count] = NULL;
	count = -1;
	i = -1;
	while (arr[++i])
	{
		if (arr[i][0] != '\0')
			res[++count] = ft_strdup(arr[i]);
	}
	free_all((void **)arr, ft_arraylen(arr));
	arr = res;
	return (arr);
}