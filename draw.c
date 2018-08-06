/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 15:29:36 by ylesik            #+#    #+#             */
/*   Updated: 2018/06/11 15:29:40 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	f_draw_x(t_mylist *list, int i, int j)
{
	list->x0 = (list->start_x + list->scale * i) - (j * list->ofset);
	list->y0 = (list->start_y + list->scale * j) -
	(list->z[j][i] * list->y_scale);
	list->x1 = (list->start_x + list->scale * (i + 1) - (j * list->ofset));
	list->y1 = (list->start_y + list->scale * j) -
	(list->z[j][i + 1] * list->y_scale);
	bresenham_line(list, i, j);
}

void	f_draw_y(t_mylist *list, int i, int j)
{
	list->x0 = (list->start_x + list->scale * i) - (j * list->ofset);
	list->y0 = (list->start_y + list->scale * j) -
	(list->z[j][i] * list->y_scale);
	list->x1 = (list->start_x + list->scale * i - ((j + 1) * list->ofset));
	list->y1 = (list->start_y + list->scale * (j + 1)) -
	(list->z[j + 1][i] * list->y_scale);
	bresenham_line(list, i, j);
}

int		f_draw(t_mylist *list)
{
	int i;
	int j;

	i = 0;
	j = 0;
	mlx_clear_window(list->mlx_ptr, list->win_ptr);
	ui(list);
	while (j < list->len_z[0])
	{
		i = 0;
		while (i < list->len_z[1])
		{
			if (i < list->len_z[1] - 1)
			{
				f_draw_x(list, i, j);
			}
			if (j < list->len_z[0] - 1)
			{
				f_draw_y(list, i, j);
			}
			i++;
		}
		j++;
	}
	return (0);
}
