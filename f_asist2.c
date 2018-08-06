/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_asist2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 20:04:33 by ylesik            #+#    #+#             */
/*   Updated: 2018/06/25 20:04:35 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int		exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

void	change_color(t_mylist *list)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < list->len_z[0])
	{
		while (i < list->len_z[1])
		{
			if (list->color[j][i] > list->color_step && list->color[j][i]
			< 0xffffff)
				list->color[j][i] = list->color[j][i] + list->color_step;
			i++;
		}
		i = 0;
		j++;
	}
	f_draw(list);
}

void	ui(t_mylist *list)
{
	mlx_string_put(list->mlx_ptr, list->win_ptr, 20, 20, 0xf47741, ZOOM);
	mlx_string_put(list->mlx_ptr, list->win_ptr, 20, 40, 0xbef441, TRANSF);
	mlx_string_put(list->mlx_ptr, list->win_ptr, 20, 60, 0x41f4eb, COLOR);
	mlx_string_put(list->mlx_ptr, list->win_ptr, 20, 80, 0x4f41f4, OFSET);
	mlx_string_put(list->mlx_ptr, list->win_ptr, 20, 100, 0xf44179, Y_STEP);
	mlx_string_put(list->mlx_ptr, list->win_ptr, 20, 120, 0xf49441, EXIT);
}
