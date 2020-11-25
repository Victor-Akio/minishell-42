/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:56:25 by vminomiy          #+#    #+#             */
/*   Updated: 2020/11/25 23:02:25 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/msh.h"


void			init(void)
{
	
}

static void		prompt(int ret)
{
	ft_putstr("\n$> ");
	ret = 0;
}

t_list			*lstadd_back(t_list *list, void *content)
{
	t_list		*x;
	t_list		*ret;

	if (!list)
		return (list_gen(content));
	ret = list;
	while (list->next)
		list = list->next;
	if (!(x = malloc(sizeof(t_list))))
	{
		write(1, "Error - Memory Allocation problem.\n", 35);
		exit(1);
	}
	x->content = content;
	x->next = NULL;
	list->next = x;
	return (ret);
}

t_list			*list_gen(void *content)
{
	t_list		*ret;

	if (!(ret = malloc(sizeof(t_list))))
	{
		write(1, "Error - Memory Allocation problem.\n", 35);
		exit(1);
	}
	ret->content = content;
	ret->next = NULL;
	return (ret);
}

t_list			*add_env(char **ev)
{
	t_list		*tmp;
	char		*str;
	int			i;

	tmp = list_gen(ev[0]);
	i = 0;
	while (ev[++i])
	{
		str = ft_strdup(ev[i]);
		tmp = lstadd_back(tmp, str);
	}
	return (tmp);
}

int				main(int ac, char **av, char **ev)
{
	// char		*com;
	t_list		*all;
	// char		**tmp;
	int			c;

	ac = 1;
	*av = NULL;
	all = add_env(ev);
	ft_putstr("\033[?1049h\033[H");
	while (c = -1)
	{
		signal(SIGINT, prompt);
		init();
	}
}