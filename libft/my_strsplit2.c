/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strsplit2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylesik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 17:26:24 by ylesik            #+#    #+#             */
/*   Updated: 2018/04/16 15:54:31 by ylesik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_index_next(char *str, char c, int skip)
{
	if (skip)
		while (*str != '\0' && *str == c)
			str++;
	else
		while (*str != '\0' && *str != c)
			str++;
	return (str);
}

char	**ft_free(char **ret, int len)
{
	int i;

	i = 0;
	while (i < len)
		free(ret[i]);
	free(ret);
	return (0);
}

int		ft_strcount(char *s1, char c)
{
	int n;
	int s;

	n = 0;
	s = 0;
	while (s1[n] != '\0')
	{
		if (s1[n] != c)
		{
			while (s1[n] != '\0' && s1[n] != c)
				n++;
			s++;
		}
		n++;
	}
	return (s);
}

void	ft_space(char *str, size_t *i)
{
	int s;

	s = 0;
	while ((str[s] == ' ') || (str[s] == '\t') || (str[s] == '\n')
			|| (str[s] == '\v') || (str[s] == '\f') || (str[s] == '\r'))
		s++;
	*i = s;
}

char	**my_strsplit2(char *s, char c)
{
	char		**ret;
	int			i;
	char		*next;

	if (s == 0)
		return (0);
	ret = (char**)malloc(sizeof(char*) * (ft_strcount(s, c) + 1));
	if (ret == 0)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		s = ft_str_index_next(s, c, 1);
		if (*s != '\0')
		{
			next = ft_str_index_next(s, c, 0);
			ret[i] = ft_strsub(s, 0, next - s);
			if (ret[i] == 0)
				return (ft_free(ret, i));
			i++;
			s = next;
		}
	}
	ret[i] = 0;
	return (ret);
}
