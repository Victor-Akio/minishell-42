/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 20:33:33 by vminomiy          #+#    #+#             */
/*   Updated: 2021/02/08 20:54:21 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			rm_backslash(char **dir, char *pos)
{
	char		*str;
	char		*tmp;

	if ((ft_strlen(str = ft_strdup(pos + 1))) == ft_strlen(*dir))
	{
		free(*dir);
		*dir = str;
	}
	else
	{
		*pos = '\0';
		tmp = ft_strjoin(*dir, str);
		free(*dir);
		free(str);
		*dir = tmp;
	}
}

static void		errno_update(char **dir)
{
	free(*dir);
	*dir = ft_itoa(errno);
}

static void		str_update(char *p, char *s, char **d, char *quot)
{
	char		*tmp;
	char		*aux;

	if (!quot)
		quot = ft_calloc(1, sizeof(char));
	p[-1] = '\0';
	tmp = ft_strdup(*d);
	aux = ft_strjoin(tmp, s);
	free(tmp);
	while (*(p++) && (p[0] != ' ') && (p[0] != '\t') && (p[0] != '\n') &&
		(p[0] != *quot))
		;
	tmp = ft_strjoin(aux, p);
	free(s);
	free(aux);
	free(*d);
	if (quot[0] == '\0')
		free(quot);
	*d = tmp;
}

void			replace_var(char **dir, char *ptr)
{
	char		*str;
	char		*tmp;
	char		*aux;

	aux = NULL;
	if (*ptr == '?')
		errno_update(dir);
	if ((tmp = non_zero_char(ft_strchr(*dir, '"'), ft_strchr(*dir, '\''))))
	{
		if ((aux = ft_strchr(tmp + 1, *tmp)))
		{
			*aux = '\0';
			str = (*tmp == '"') ? env_selector(ptr) : ft_strdup(ptr - 1);
			*aux = *tmp;
		}
		else
			str = (*tmp == '"') ? env_selector(ptr) : ft_strdup(ptr - 1);
	}
	else
		str = env_selector(ptr);
	str_update(ptr, str, dir, aux);
}

void			replace_env(t_commands *table)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	while (table->coms[++i])
	{
		j = -1;
		while (table->coms[i][++j])
		{
			if ((tmp = ft_strchr(table->coms[i][j], '$')))
			{
				if (((tmp - table->coms[i][j]) != 0) && (tmp[-1] == '\\'))
					rm_backslash(&table->coms[i][j], tmp - 1);
				else
					replace_var(&table->coms[i][j], tmp + 1);
			}
		}
	}
}
