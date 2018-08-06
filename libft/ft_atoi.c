/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:09:43 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/16 13:36:41 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		minus;
	size_t	result;

	minus = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((result > 922337203685477580 || (result == 922337203685477580
						&& (*str - '0') > 7)) && minus == 1)
			return (-1);
		else if ((result > 922337203685477580 || (result == 922337203685477580
						&& (*str - '0') > 8)) && minus == -1)
			return (0);
		result = (result * 10) + (*str - '0');
		str++;
	}
	return ((minus < 0 ? -result : result));
}
