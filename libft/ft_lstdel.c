/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 21:09:24 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/15 15:02:42 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst && del)
	{
		ft_lstdel(&(**alst).next, del);
		del((**alst).content, (**alst).content_size);
		free(*alst);
		*alst = NULL;
	}
}
