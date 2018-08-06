/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:28:35 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/16 16:41:25 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_factorial(int n)
{
	int i;

	i = 1;
	if ((i >= 0) && (i <= 12))
	{
		while (n > 0)
		{
			i = i * n;
			n--;
		}
		return (i);
	}
	else
		return (0);
}
