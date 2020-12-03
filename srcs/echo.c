/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:42:53 by vminomiy          #+#    #+#             */
/*   Updated: 2020/11/30 00:06:24 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*ft_ignorechar(char **line, char c)
{
	while(**line == c)
		(*line)++;
	return (*line);
}

char			*env_selector(char *ev)
{
	int			len;
	char		*res;
	int			i;

	i = -1;
	while (ev[++i] && (ev[i] != ' ') && (ev[i] != '\t') && (ev[i] != '\'')
		&& (ev[i] != '"') && (ev[i] != '\n'))
		;
	len = i;
	i = 0;
	while (tmp_env[i] && ft_strncmp(ev, tmp_env[i], len) != 0)
		i++;
	if (!tmp_env[i] || tmp_env[i][len] != '=')
		res = ft_strdup("");
	else
		res = ft_substr(tmp_env[i], len + 1, ft_strlen(tmp_env[i]));
	return (res);
}

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
	while (*(p++) && (p[0] != ' ') && (p[0] != '\t') && (p[0] != '\n') && (p[0] != *quot))
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
	char 		*str;
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

int				read_subshell(char **input, char c)
{
	char		buff[1];
	int			bytes;
	char		*tmp;

	*input = ft_addchar(*input, '\n');
	while ((bytes = read(0, buff, 1)) && (buff[0] != c))
		*input = ft_addchar(*input, buff[0]);
	read(0, buff, 1);
	if (!bytes)
		write(2, "ERROR - Problem to find matcher quote.\n", 39);
	else
		*input = ft_addchar(*input, c);
	if ((tmp = ft_strchr(*input, '$')))
	{
		if (((tmp - *input) != 0) && (tmp[-1] == '\\'))
			rm_backslash(input, tmp - 1);
		else
			replace_var(input, tmp -1);
	}
	return (bytes);
}

int				quot_parser(char **arg, int i)
{
	char		*ptr;
	int			ret;

	ret = 1;
	if ((ptr = non_zero_char(ft_strchr(arg[i], '"'), ft_strchr(arg[i], '\''))) && !(ft_strchr(ptr + 1, *ptr)))
		ret = read_subshell(arg + i, *ptr);
	if (!ret)
		return (0);
	return (1);
}

void			com_echo(char **arg)
{
	int			i;
	int			j;

	i = 1;
	if (arg[i] && (arg[1][0] == '-' && arg[1][1] == 'n' && arg[1][2] == 0))
		i++;
	j = i;
	while (arg[j])
		if (!quot_parser(arg, j++))
			return ;
	while (arg[i])
	{
		rm_quotes(arg + i);
		write(1, arg[i], ft_strlen(arg[i]));
		if (arg[++i])
			write(1, " ", 1);
	}
	if (arg[1] && (arg[1][0] == '-' && arg[1][1] == 'n' && arg[1][2] == 0))
		;
	else
		write(1, "\n", 1);
	errno = 0;
}