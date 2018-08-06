/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 18:21:04 by ylesik            #+#    #+#             */
/*   Updated: 2018/06/01 18:21:05 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define BUFF_SIZE 10000
# define ZOOM "button + zoom up / button - zoom down"
# define TRANSF "button arrow right/left/up/down - image right/left/up/down"
# define COLOR "button 1 / button 2 - change the color of the image"
# define OFSET "num button 1 / num button 2 - change the position base"
# define Y_STEP "num button 4 / num button 5 - change 'z axis'"
# define EXIT "Press ESC button to exit"

# include "mlx.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

typedef	struct		s_fdf_list
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			**map;
	int				**z;
	int				*len_z;
	int				**color;

	int				x0;
	int				x1;
	int				y0;
	int				y1;

	int				win_size_w;
	int				win_size_h;

	int				deltax;
	int				deltay;

	int				y_step;
	int				x_step;

	int				scale;
	float			ofset;
	float			ofset_help;
	int				y_scale;

	int				start_x;
	int				start_y;

	int				color_step;
}					t_mylist;

int					exit_x(void *par);
int					my_abs(int nb);
void				ft_putchar(char c);
int					f_draw(t_mylist *list);
void				bresenham_line(t_mylist *list, int i, int j);
int					**ft_len(char **map, t_mylist *list);
void				ft_assign(t_mylist *list);
void				input(char *argv, t_mylist *list);
long int			ft_atoi_base(char *str, int base);
void				ft_save_color(t_mylist *list);
int					ft_save_color_help(t_mylist *list, int j, int i, int swich);
void				ui(t_mylist *list);
void				change_color(t_mylist *list);

#endif
