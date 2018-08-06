/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:24:02 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/11 18:03:23 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int nb;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648\0", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 0 && n <= 9)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		nb = n % 10;
		ft_putchar_fd((nb) + '0', fd);
	}
}
