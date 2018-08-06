/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 18:46:02 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/16 13:37:28 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *start_new;

	new = NULL;
	if (lst && f)
	{
		if (!(new = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		new = f(lst);
		if (new == NULL)
			return (NULL);
		start_new = new;
		while (lst->next)
		{
			lst = lst->next;
			new->next = f(lst);
			new = new->next;
		}
		return (start_new);
	}
	return (NULL);
}
