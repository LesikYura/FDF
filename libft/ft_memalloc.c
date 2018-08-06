/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:34:13 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/16 15:30:28 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void		*adr;
	size_t		i;

	i = 0;
	adr = NULL;
	if (size > 4294967295)
		return (NULL);
	if (!(adr = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	while (i < size)
	{
		((unsigned char *)adr)[i] = 0;
		i++;
	}
	return (adr);
}
