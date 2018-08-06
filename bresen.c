/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:27:51 by ylesik            #+#    #+#             */
/*   Updated: 2018/06/15 15:28:37 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	for_dx(t_mylist *list, int i, int j)
{
	int error;
	int q;
	int x;
	int y;

	error = (list->deltay << 1) - list->deltax;
	x = list->x0 + list->x_step;
	y = list->y0;
	q = 1;
	mlx_pixel_put(list->mlx_ptr, list->win_ptr, list->x0, list->y0,
	list->color[j][i]);
	while (q <= list->deltax)
	{
		if (error > 0)
		{
			y += list->y_step;
			error += (list->deltay - list->deltax) << 1;
		}
		else
			error += list->deltay << 1;
		mlx_pixel_put(list->mlx_ptr, list->win_ptr, x, y, list->color[j][i]);
		x += list->x_step;
		q++;
	}
}

void	for_dy(t_mylist *list, int i, int j)
{
	int error;
	int q;
	int x;
	int y;

	error = (list->deltax << 1) - list->deltay;
	y = list->y0 + list->y_step;
	x = list->x0;
	q = 1;
	mlx_pixel_put(list->mlx_ptr, list->win_ptr, list->x0, list->y0,
	list->color[j][i]);
	while (q <= list->deltay)
	{
		if (error > 0)
		{
			error += (list->deltax - list->deltay) << 1;
			x += list->x_step;
		}
		else
			error += list->deltax << 1;
		mlx_pixel_put(list->mlx_ptr, list->win_ptr, x, y, list->color[j][i]);
		y += list->y_step;
		q++;
	}
}

void	bresenham_line(t_mylist *list, int i, int j)
{
	list->deltax = abs(list->x1 - list->x0);
	list->deltay = abs(list->y1 - list->y0);
	list->x_step = list->x1 >= list->x0 ? 1 : -1;
	list->y_step = list->y1 >= list->y0 ? 1 : -1;
	if (list->deltax > list->deltay)
		for_dx(list, i, j);
	else
		for_dy(list, i, j);
}
