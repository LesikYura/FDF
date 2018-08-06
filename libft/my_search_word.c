/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_search_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:53:27 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/16 16:40:20 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_search_word(const char *s, char c)
{
	int i;
	int words_count;
	int flag;

	i = 0;
	words_count = 0;
	flag = 1;
	while (i < (int)ft_strlen(s))
	{
		while (s[i] == c)
		{
			if (s[i + 1] != c && s[i + 1] != '\0')
				flag = 1;
			else
				flag = 0;
			i++;
		}
		if (flag == 1)
			words_count++;
		flag = 0;
		i++;
	}
	return (words_count);
}
