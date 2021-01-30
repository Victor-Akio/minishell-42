/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 21:01:31 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/30 17:19:04 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				quote_handler(char **arg, int i)
{
	char	*ptr;
	int		ret;

	ret = 1;
	if ((ptr = non_zero_char(ft_strchr(arg[i], '"'),
			ft_strchr(arg[i], '\''))) && !(ft_strchr(ptr + 1, *ptr)))
		ret = input_minishell(arg + i, *ptr);
	if (!ret)
		return (0);
	return (1);
}

int				envp_len(char **envp)
{
	int len;

	len = -1;
	while (envp[++len])
		;
	return (len);
}

int				check_empty_com(char **table, char **input)
{
	int			i;
	int			j;

	i = -1;
	j = ft_arraylen(table);
	while (table[++i])
	{
		if (((table[i][0] == '\0') || ft_all_spaces(table[i])) && (j != 1))
		{
			write(2, "ERROR - Syntax error.\n", 22);
			free(input);
			*input = NULL;
			free_all((void **)table, ft_arraylen(table));
			return (1);
		}
	}
	return (0);
}

char			*ft_strquot_aux(char **quotpos, char *str, char c)
{
	int			i;
	int			x;

	x = ft_arraylen(quotpos);
	i = -1;
	while ((str[++i]) && (str[i + 1]))
	{
		if ((str[i] == c) && (str[i + 1] == c) &&
			((between_quot_pair(quotpos, str + i) != -1)
			|| ((x % 2) && (str + i > quotpos[x - 1]))))
			continue ;
		else if ((str[i] == c) && (str[i + 1] == c))
			return (str + i + 1);
	}
	return (0);
}

void			read_input(char **input)
{
	char		buff[1];
	int			bytes;

	while ((bytes = read(0, buff, 1)) && buff[0] != '\n')
		*input = ft_addchar(*input, buff[0]);
	*input = ft_addchar(*input, '\0');
	if (!bytes)
	{
		free(*input);
		msh_exit();
	}
}