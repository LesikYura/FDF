/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 20:00:39 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/16 13:38:03 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;
	int			dst_tmp;

	dst_tmp = ft_strlen(dst);
	i = dst_tmp;
	if (i < dstsize)
	{
		j = 0;
		dstsize = dstsize - i - 1;
		while (j < dstsize && src[j] != '\0')
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	else
		return (ft_strlen(src) + dstsize);
	return (dst_tmp + ft_strlen(src));
}
