/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:01:58 by vminomiy          #+#    #+#             */
/*   Updated: 2021/01/20 17:26:09 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		reset_values(int *fd)
{
	dup2(fd[0], 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
}

static void		redirect_input(t_commands *table, int *i, int *fd)
{
	if (!(table->i_files[i[1]][0]) && (i[1] == 0))
		fd[2] = dup(fd[0]);
	else if (i[1] == 0)
		fd[2] = open(table->i_files[i[1]][0], O_RDONLY);
	dup2(fd[2], 0);
	close(fd[2]);
}

static void		redirect_output(t_commands *table, int *i, int *fd, int *pp)
{
	int			x;

	x = table->com_index - 1;
	if ((i[1] == x) && !(table->o_files[i[1]][0]) &&
		!(table->ap_files[i[1]][0]))
		fd[3] = dup(fd[1]);
	else if ((i[1] == x) && (table->ap_files[i[1]][0]))
		fd[3] = open(table->ap_files[i[1]][0], O_CREAT | O_WRONLY |
			O_APPEND, S_IWUSR | S_IRUSR);
	else if ((i[1] == x) && (table->o_files[i[1]][0]))
		fd[3] = open(table->o_files[i[1]][0], O_CREAT | O_WRONLY |
			O_APPEND, S_IWUSR | S_IRUSR);
	else if (i[1] == x)
	{
		pipe(pp);
		fd[3] = pp[1];
		fd[2] = pp[0];
	}
	dup2(fd[3], 1);
	close(fd[3]);
}

static void		tmp_files(char **arr)
{
	int			i;

	i = -1;
	while (arr[++i])
	{
		if (open(arr[i], O_CREAT, S_IRUSR | S_IWUSR) < 0)
		{
			write(2, "ERROR - ", 8);
			write(2, strerror(errno), ft_strlen(strerror(errno)));
		}
	}
}

void			execute_com(t_commands *table, int index)
{
	int			i[2];
	int			fd[4];
	int			pp[2];

	i[0] = -1;
	while (++(i[0]) < index)
	{
		fd[0] = dup(0);
		fd[1] = dup(1);
		i[1] = -1;
		while ((table[i[0]].coms[++(i[1])]))
		{
			redirect_input(table + i[0], i, fd);
			redirect_output(table + i[0], i, fd, pp);
			tmp_files(table[i[0]].d_files[i[1]]);
			if (coms_handler(table[i[0]].coms[i[1]]))
				pick_com_exec(table[i[0]].coms[i[1]], table + i[0]);
			else if ((exec_pathfinder(table[i[0]].coms[i[1]])))
				launch_exec(table[i[0]].coms[i[1]]);
			else if (table[i[0]].coms[i[1]][0] != NULL)
				coms_not_found(table[i[0]].coms[i[1]][0]);
		}
		reset_values(fd);
	}
	free_table(table, index);
}
