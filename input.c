/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:04:43 by ylesik            #+#    #+#             */
/*   Updated: 2018/06/26 15:04:46 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int ret, int fd, char *argv)
{
	char *err;

	if (fd < 0)
	{
		perror(argv);
		exit(0);
	}
	if (ret < 0)
	{
		err = strerror(errno);
		ft_putstr(err);
		ft_putstr("\n");
		exit(0);
	}
}

void	input(char *argv, t_mylist *list)
{
	int		fd;
	int		ret;
	char	*tmp;
	char	*buff;
	char	**result;

	buff = ft_strnew(BUFF_SIZE);
	tmp = ft_strnew(0);
	fd = open(argv, O_RDONLY);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = my_strjoin_free(tmp, buff);
	}
	ft_error(ret, fd, argv);
	result = my_strsplit2(tmp, '\n');
	list->map = result;
	close(fd);
	ft_strdel(&tmp);
	ft_strdel(&buff);
}
