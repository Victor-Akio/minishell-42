/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 02:42:15 by vminomiy          #+#    #+#             */
/*   Updated: 2020/12/03 21:51:43 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			rm_quotes(char **arr)
{
	int			i;
	char		*quotpos[2];
	char		*tmp;

	i = -1;
	if (!*arr)
		return ;
	while (*(*arr + ++i))
	{
		if ((quotpos[0] = non_zero_char(ft_strchr(*arr, '"'),
			ft_strchr(*arr, '\''))) && (quotpos[1] = ft_strchr(quotpos[0] + 1,
			*quotpos[0])))
		{
			*quotpos[0] = '\0';
			*quotpos[1] = '\0';
			tmp = ft_strjoin(*arr, quotpos[0] + 1);
			free(*arr);
			*arr = tmp;
		}
	}
}

/*
** This functions is responsible to pick the smallets non zero command
*/

char			*non_zero_char(char *p1, char *p2)
{
	if (!p1 && !p2)
		return (NULL);
	else if (!p1)
		return (p2);
	else if (!p2)
		return (p1);
	else
		return ((p1 < p2) ? p1 : p2);
}

/*
** char_verify will validate the Quoted commands
*/

static int		char_verify(char **quotpos, char c)
{
	int			i;
	char		*ptr;

	i = 0;
	while ((quotpos[i]) && (quotpos[i + 1]))
	{
		*quotpos[i + 1] = '\0';
		ptr = ft_strchr(quotpos[i], c);
		*quotpos[i + 1] = *quotpos[i];
		if (ptr)
			return (1);
		else
			i += 2;
	}
	return (0);
}

/*
** It will remove the '\"' dummies.
*/

void			rm_dummies(char **table)
{
	int			i;
	char		*quotpos[2];
	char		*tmp;

	i = 0;
	while (table[i])
	{
		if ((quotpos[0] = non_zero_char(ft_strchr(table[i], '"'), ft_strchr(table[i], '\'')))
			&& (quotpos[1] = ft_strchr(quotpos[0] + 1, *quotpos[0]))
			&& ((quotpos[1] - quotpos[0]) == 1))
		{
			*quotpos[0] = '\0';
			*quotpos[1] = '\0';
			tmp = ft_strdup(quotpos[1] + 1);
			free(table[i]);
			table[i] = tmp;
		}
		i++;
	}
}

/*
** Between_quotes_pair, wil pick the content betweent the quotes and save
*/

int				between_quot_pair(char **quotpos, char *pos)
{
	int			i;

	i = 0;
	while ((quotpos[i]) && (quotpos[i + 1]))
	{
		if ((pos > quotpos[i]) && (quotpos[i + 1]))
			return (i);
		else
			i += 2;
	}
	return (-1);
}

/*
** Count_unquoted will count every command that is not between quotes
*/

int				count_unquoted(char **quotpos, char *str, char c)
{
	int			i;
	int			j;
	int			count;

	i = -1;
	j = ft_arraylen(quotpos);
	count = 0;
	while (str[++i])
	{
		if ((str[i] == c) && ((between_quot_pair(quotpos, str + i) != -1)
			|| ((j % 2) && (str + i > quotpos[j + 1]))))
			continue;
		else if (str[i] == c)
			count++;
	}
	return (count);
}

/*
** Create and allocate the command array
*/

char			**set_pos(char *str)
{
	char		*ptr;
	char		**quotpos;

	quotpos = malloc(sizeof(char *) * 1);
	*quotpos = NULL;
	while ((ptr = non_zero_char(ft_strchr(str, '"'), ft_strchr(str, '\''))))
	{
		if ((str = ft_strchr(ptr +1, *ptr)))
		{
			ft_addstr(&quotpos, ptr);
			ft_addstr(&quotpos, str);
			str++;
		}
		else
		{
			ft_addstr(&quotpos, ptr);
			break;
		}
	}
	return (quotpos);
}

/*
** I will find the content of the Quoted parts
*/

char			*ft_strquots(char **quotpos, char *str, char c)
{
	int			i;
	int			j;

	if (!str)
		return (0);
	if (!quotpos[0])
		return (ft_strchr(str, c));
	j = ft_arraylen(quotpos);
	i = -1;
	while (str[++i])
	{
		if ((between_quot_pair(quotpos, str + i) != -1)
			&& ((j % 2) && (str + i > quotpos[j -1])))
			continue;
		else if (str[i] == c)
			return (str + i);
	}
	return (0);
}

/*
** With every data separated, the table will be populates accordingly.
*/

static void		table_loop(char **tab, char *str, char c, char **quotpos)
{
	int			i;
	char		*pos;

	i = -1;
	while ((pos = ft_strquots(quotpos, str, c)))
	{
		*pos = '\0';
		tab[++i] = ft_strdup(str);
		str = pos + 1;
	}
	tab[++i] = ft_strdup(str);
}

/*
** Split_quots is responsible to separate every command. Remember to remove the dummies quotes, that should not be processed as command.
*/

char			**split_quots(char *str, char c)
{
	char		**quotpos;
	char		**table;
	int			count;

	quotpos = set_pos(str);
	if (!(quotpos[0]) || !(char_verify(quotpos, c)))
	{
		free(quotpos);
		return (ft_split(str, c));
	}
	count = count_unquoted(quotpos, str, c);
	table = malloc(sizeof(char *) * (count + 2));
	table[count + 1] = NULL;
	table_loop(table, str, c, quotpos);
	rm_dummies(table);
	free(quotpos);
	return (table);
}

/*
** we need to remove the unnecessary blank string 
*/

char			**rm_empty_str(char **arr)
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