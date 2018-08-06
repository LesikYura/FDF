/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:29:00 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/11 12:40:37 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	int			j;
	size_t		i_t;

	if (needle[0] == '\0')
		return ((char*)&haystack[0]);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			i_t = i;
			while (haystack[i_t] == needle[j] && j < (int)ft_strlen(needle))
			{
				j++;
				i_t++;
			}
			if (needle[j] == '\0' && i_t <= len)
				return ((char*)haystack + i);
		}
		i++;
	}
	return (0);
}
