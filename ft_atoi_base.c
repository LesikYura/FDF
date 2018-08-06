/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 11:51:54 by ylesik            #+#    #+#             */
/*   Updated: 2018/07/02 17:30:45 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int		conver(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

long	int		ft_atoi_base(char *str, int base)
{
	int result;
	int minus;
	int i;

	i = 0;
	minus = 1;
	result = 0;
	if (!str)
		return (0);
	while (str[i] <= 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
		|| (str[i] >= 'A' && str[i] <= 'F'))
		result = result * base + (conver(str[i++]));
	return (result * minus);
}
