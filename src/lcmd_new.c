/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcmd_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 02:57:31 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/30 18:12:51 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lcmd_new(t_lstcmds *lcmd, char *name, char *dt, int fdi, int fdo)
{
	t_lstcmds	*l;
	t_lstcmds	*nls;

	if(!(l = (t_lstcmds *)malloc(sizeof(t_lstcmds))))
		return (-1);
	l->data = dt;
	l->name = name;
	l->fdin = fdi;
	l->fdout = fdo;
	nls = lcmd_last(lcmd);
	if (nls == NULL)
		nls = l;
	else
	{
		l->prev = nls;
		nls->next = l;
		l->next = NULL;
	}
	return (1);
}