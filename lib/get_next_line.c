/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 03:25:08 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/25 22:45:19 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gnl_ft_strdel(char **s)
{
	if (*s != NULL || s != NULL)
	{
		free(*s);
		*s = NULL;
	}
}

int		gnl_ft_creatline(char **s, char **line)
{
	int		n;
	char	*aux;

	n = gnl_ft_findchar(*s, '\n');
	if (n < 0)
		n = gnl_ft_strlen(*s);
	*line = gnl_ft_substr(*s, 0, n);
	aux = gnl_ft_substr(*s, n + 1, gnl_ft_strlen(*s) - n);
	gnl_ft_strdel(s);
	*s = aux;
	aux = NULL;
	return (1);
}

int		gnl_core(int fd, char *buff, char **s, char **line)
{
	int		ret;
	char	*tmp;

	while (gnl_ft_findchar(*s, '\n') < 0)
	{
		if ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
		{
			buff[ret] = '\0';
			tmp = gnl_ft_strjoin(*s, buff);
			gnl_ft_strdel(s);
			*s = tmp;
		}
		else if (ret == 0)
		{
			gnl_ft_creatline(s, line);
			gnl_ft_strdel(s);
			return (0);
		}
		else
			return (-1);
	}
	gnl_ft_creatline(s, line);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		*buff;
	int			aux;

	if ((fd < 0 || fd >= OPEN_MAX) || line == NULL
		|| BUFFER_SIZE < 1 || (read(fd, NULL, 0))
		|| !(buff = gnl_ft_calloc(BUFFER_SIZE + 1)))
		return (-1);
	if (!str[fd] && !(str[fd] = gnl_ft_calloc(1)))
		return (-1);
	aux = gnl_core(fd, buff, &str[fd], line);
	gnl_ft_strdel(&buff);
	return (aux);
}