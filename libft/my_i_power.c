/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_i_power.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:32:32 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/16 16:38:17 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_i_power(int n, int power)
{
	int result;

	result = n;
	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		while (power > 1)
		{
			result = result * n;
			power--;
		}
		return (result);
	}
}
