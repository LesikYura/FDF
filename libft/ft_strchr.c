/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 21:35:44 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/16 17:58:09 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char n;

	n = c;
	if (*s || s != NULL)
	{
		while (*s != '\0')
		{
			if (*s == n)
				return ((char*)s);
			s++;
		}
		if (*s == n)
			return ((char*)s);
	}
	return (NULL);
}
