/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 20:30:27 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/14 19:00:07 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** free_all will do the free job throught the program 
*/

void			free_array(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return ;
}

void			free_all(void **buff, int len)
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

int				free_parser_error(t_commands *table, int index, char **coms)
{
	int			i;
	int			j;

	write(2, "ERROR - parse error.\n", 21);
	free_all((void **)coms, ft_arraylen(coms));
	i = -1;
	while (++i <= index)
	{
		j = -1;
		while (++j < table[i].com_index)
		{
			ft_freearray(table[i].coms[j]);
			ft_freearray(table[i].i_files[j]);
			ft_freearray(table[i].o_files[j]);
			ft_freearray(table[i].ap_files[j]);
			ft_freearray(table[i].d_files[j]);
		}
		free_ptrs(table + i);
	}
	free(table);
	return (1);
}

void			free_ptrs(t_commands *table)
{
	free(table->coms);
	free(table->i_files);
	free(table->o_files);
	free(table->ap_files);
	free(table->d_files);
}

void			free_table(t_commands *table, int index)
{
	int 		i;
	int			j;

	i = -1;
	while (++i < index)
	{
		j = -1;
		while (++j < table[i].com_index)
		{
			free_all((void **)table[i].coms[j], ft_arraylen(table[i].coms[j]));
			free_all((void **)table[i].i_files[j], ft_arraylen(table[i].i_files[j]));
			free_all((void **)table[i].o_files[j], ft_arraylen(table[i].o_files[j]));
			free_all((void **)table[i].ap_files[j], ft_arraylen(table[i].ap_files[j]));
			free_all((void **)table[i].d_files[j], ft_arraylen(table[i].d_files[j]));
		}
		free_ptrs(table + i);
	}
	free(table);
}