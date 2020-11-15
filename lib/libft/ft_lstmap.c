/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 05:02:15 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/06 02:24:30 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*first;

	first = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		nlst = ft_lstnew((f)(lst->content));
		if (nlst == NULL)
		{
			if (first != NULL)
				ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, nlst);
		lst = lst->next;
	}
	return (first);
}
