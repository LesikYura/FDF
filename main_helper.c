/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 20:12:29 by ylesik            #+#    #+#             */
/*   Updated: 2018/06/25 20:12:32 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_assign_window(t_mylist *list)
{
	if (list->len_z[1] < 40)
	{
		list->win_size_w = 800;
		list->win_size_h = 450;
		list->scale = 14;
		list->ofset = 8;
	}
	else if (list->len_z[1] >= 40 && list->len_z[1] < 140)
	{
		list->win_size_w = 1600;
		list->win_size_h = 900;
		list->scale = 9;
		list->ofset = 4;
	}
	else if (list->len_z[1] >= 140)
	{
		list->win_size_w = 2500;
		list->win_size_h = 1300;
		list->scale = 3;
		list->ofset = 2;
	}
}

void	ft_assign(t_mylist *list)
{
	ft_assign_window(list);
	list->color_step = 1000;
	list->ofset_help = 0.2;
	list->start_x = list->win_size_w / 2.5;
	list->start_y = 150;
	list->y_scale = 2;
}

int		ft_save_color_help(t_mylist *list, int j, int i, int swich)
{
	if (swich == 0)
	{
		while (list->map[j][i] != ' ' && list->map[j][i] != '\n'
		&& list->map[j][i] != '\0')
			i++;
		if (list->map[j][i] != '\n' && list->map[j][i] != '\0')
			i++;
		return (i);
	}
	else
	{
		while (list->map[j][i] == ' ')
			i++;
		while (ft_isdigit(list->map[j][i]) || list->map[j][i] == '-')
			i++;
		return (i);
	}
}

void	ft_save_color(t_mylist *list)
{
	int i;
	int j;
	int n;

	j = -1;
	while (list->map[++j] != NULL)
	{
		n = -1;
		i = 0;
		while (list->map[j][i])
		{
			i = ft_save_color_help(list, j, i, 1);
			if (list->map[j][i] == ',')
			{
				i = i + 3;
				list->color[j][++n] = ft_atoi_base(&(list->map[j][i]), 16);
				i = ft_save_color_help(list, j, i, 0);
			}
			else
			{
				list->color[j][++n] = 0x75a0e5;
				i = ft_save_color_help(list, j, i, 0);
			}
		}
	}
}
