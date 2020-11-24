/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_getline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 22:15:12 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/11/19 23:39:03 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char *msh_getline(void)
{
	int ret;
	char *c;
	char *input;
	char *tmp;
	int fdin;

	fdin = 0; //stdin

	// if (fdin < 0)
	// 	return (NULL);
	if (!(input = ft_strdup("")) || !(c = ft_calloc(2, sizeof(char))))
		return (NULL);
	printf("aaaaa ");
	while(((ret = read(fdin, c, 1)) > 0) && !(ft_strncmp(c, "\n", 1) ))
	{
		tmp = ft_strjoin(input, c);
		ft_strdel(&input);
		input = tmp;
		if (ft_strchr(input, '\n')){
			printf("%s\n", input);
			break ;
		}
	}
	return (input);
}