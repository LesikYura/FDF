/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:20:08 by ylesik            #+#    #+#             */
/*   Updated: 2018/05/30 16:26:52 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	deal_key_help2(int key, t_mylist *list)
{
	if (key == 83)
	{
		list->ofset = list->ofset - 1;
		f_draw(list);
	}
	if (key == 84)
	{
		list->ofset = list->ofset + 1;
		f_draw(list);
	}
	if (key == 86)
	{
		list->y_scale = list->y_scale - 1;
		f_draw(list);
	}
	if (key == 87)
	{
		list->y_scale = list->y_scale + 1;
		f_draw(list);
	}
	if (key == 19)
	{
		list->color_step = 1000;
		change_color(list);
	}
}

void	deal_key_help(int key, t_mylist *list)
{
	if (key == 123)
	{
		list->start_x = list->start_x - list->scale;
		f_draw(list);
	}
	if (key == 125)
	{
		list->start_y = list->start_y + list->scale;
		f_draw(list);
	}
	if (key == 126)
	{
		list->start_y = list->start_y - list->scale;
		f_draw(list);
	}
	if (key == 18)
	{
		list->color_step = -1000;
		change_color(list);
	}
}

int		deal_key(int key, t_mylist *list)
{
	if (key == 53)
		exit_x(list->win_ptr);
	if (key == 69)
	{
		list->scale = list->scale + 2;
		list->ofset = list->ofset + 1;
		f_draw(list);
	}
	if (key == 78)
	{
		list->scale = list->scale - 2;
		list->ofset = list->ofset - 1;
		f_draw(list);
	}
	if (key == 124)
	{
		list->start_x = list->start_x + list->scale;
		f_draw(list);
	}
	if (key == 123 || key == 125 || key == 126 || key == 18)
		deal_key_help(key, list);
	if (key == 83 || key == 84 || key == 86 || key == 87 || key == 19)
		deal_key_help2(key, list);
	return (0);
}

void	write_cord(t_mylist *list)
{
	int i;
	int j;
	int n;

	j = 0;
	while (list->map[j] != NULL)
	{
		n = 0;
		i = 0;
		while (list->map[j][i])
		{
			if (list->map[j][i] == ',')
				i = ft_save_color_help(list, j, i, 0);
			list->z[j][n] = ft_atoi_base(&(list->map[j][i]), 10);
			while (ft_isdigit(list->map[j][i]) || list->map[j][i] == '-')
				i++;
			while (list->map[j][i] == ' ')
				i++;
			n++;
		}
		j++;
	}
}

int		main(int argc, char **argv)
{
	t_mylist	list;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf source file\n");
		return (0);
	}
	input(argv[1], &list);
	list.z = ft_len(list.map, &list);
	write_cord(&list);
	ft_save_color(&list);
	list.mlx_ptr = mlx_init();
	ft_assign(&list);
	if (!list.mlx_ptr)
		return (0);
	list.win_ptr = mlx_new_window(list.mlx_ptr, list.win_size_w,
	list.win_size_h, "mlx 42");
	f_draw(&list);
	mlx_hook(list.win_ptr, 2, 5, deal_key, &list);
	mlx_hook(list.win_ptr, 17, 1L << 17, exit_x, &list);
	mlx_loop(list.mlx_ptr);
	return (0);
}
