/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 14:22:18 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/11 11:55:43 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int			i;
	size_t		j;
	int			i_t;

	if (needle[0] == '\0' || ft_strcmp(haystack, needle) == 0)
		return ((char*)&haystack[0]);
	i = 0;
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			i_t = i;
			while (haystack[i_t] == needle[j] && j < ft_strlen(needle))
			{
				j++;
				i_t++;
			}
			if (needle[j] == '\0')
				return ((char*)haystack + i);
		}
		i++;
	}
	return (0);
}
