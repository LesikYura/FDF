/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:45:30 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/16 15:10:30 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_t;
	unsigned char	*src_t;

	dst_t = (unsigned char*)dst;
	src_t = (unsigned char*)src;
	if (dst_t > src_t)
	{
		dst_t = dst_t + len - 1;
		src_t = src_t + len - 1;
		while (len--)
			*dst_t-- = *src_t--;
	}
	else
	{
		ft_memcpy(dst_t, src_t, len);
	}
	return (dst);
}
