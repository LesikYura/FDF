/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 22:12:20 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/12 16:45:45 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char*)&s[i]);
	while (i > 0)
	{
		if ((char)s[--i] == (char)c)
			return ((char*)&s[i]);
	}
	return (NULL);
}
