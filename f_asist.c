/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_asist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 16:20:08 by ylesik            #+#    #+#             */
/*   Updated: 2018/05/30 16:26:52 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_len2(char **map, t_mylist *list, int **len, int *itr)
{
	while (map[++itr[0]] != NULL)
	{
		itr[1] = 0;
		while (map[itr[0]][itr[1]] != '\n' && map[itr[0]][itr[1]] != '\0')
		{
			if (itr[1] == 0 && map[itr[0]][itr[1]] != ' ')
				itr[2]++;
			if (map[itr[0]][itr[1]] == ' ')
			{
				while (map[itr[0]][itr[1]] == ' ')
					itr[1]++;
				if (map[itr[0]][itr[1]] == '\n' || map[itr[0]][itr[1]] == '\0')
					itr[2]--;
				itr[2]++;
			}
			if (map[itr[0]][itr[1]] != '\n' && map[itr[0]][itr[1]] != '\0')
				itr[1]++;
		}
		list->len_z[itr[0] + 1] = itr[2];
		len[itr[0]] = (int *)malloc(sizeof(int) * (itr[2] + 1));
		list->color[itr[0]] = (int *)malloc(sizeof(int) * (itr[2] + 1));
		itr[2] = 0;
	}
}

void	ft_len_ver(t_mylist *list)
{
	int i;
	int k;

	i = 1;
	k = list->len_z[1];
	while (i < list->len_z[0])
	{
		if (i + 1 < list->len_z[0])
			k = list->len_z[i + 1];
		if (list->len_z[i] != k)
		{
			ft_putstr("Not all points are present, the map is not valid!\n");
			exit(0);
		}
		i++;
	}
}

int		**ft_len(char **map, t_mylist *list)
{
	int **len;
	int i;
	int itr[3];

	i = 0;
	itr[0] = -1;
	itr[1] = 0;
	itr[2] = 0;
	while (map[i] != NULL)
		i++;
	len = (int **)malloc(sizeof(int *) * (i + 1));
	list->color = (int **)malloc(sizeof(int *) * (i + 1));
	list->len_z = (int *)malloc(sizeof(int) * (i + 1));
	list->len_z[0] = i;
	ft_len2(map, list, len, itr);
	if (list->len_z[0] <= 2)
	{
		ft_putstr("The number of points in the file is not enough!\n");
		exit(0);
	}
	ft_len_ver(list);
	return (len);
}
