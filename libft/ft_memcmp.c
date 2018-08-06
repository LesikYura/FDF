/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 15:01:33 by ylesik            #+#    #+#             */
/*   Updated: 2018/03/31 17:08:04 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s1_s;
	unsigned char *s2_s;

	s1_s = (unsigned char*)s1;
	s2_s = (unsigned char*)s2;
	while (n > 0 && *s1_s == *s2_s)
	{
		s1_s++;
		s2_s++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*s1_s - *s2_s);
}
