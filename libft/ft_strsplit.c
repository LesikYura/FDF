/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:26:24 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/16 15:54:31 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	size_t		i[3];
	char		**str;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = ((char **)malloc(sizeof(char *) * (my_search_word(s, c) + 1)))))
		return (NULL);
	while (i[2] <= ft_strlen(s))
	{
		if ((i[2] - i[0]) && ((char)s[i[2]] == c || (char)s[i[2]] == '\0'))
		{
			str[i[1]++] = ft_strsub(s, (i[0]), (i[2] - i[0]));
			i[0] = i[2] + 1;
		}
		else if ((char)s[i[2]] == c)
			i[0]++;
		i[2]++;
	}
	str[i[1]] = NULL;
	return (str);
}
