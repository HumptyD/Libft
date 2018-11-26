/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:23:47 by jlucas-l          #+#    #+#             */
/*   Updated: 2018/11/25 16:46:35 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		count_words(const char *s, char c)
{
	int		count;
	int		flag;

	flag = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		if (*s == c && flag == 1)
			flag = 0;
		s++;
	}
	return (count);
}

static	char	*ft_allocateword(const char *s, char c)
{
	size_t	count;
	char	*res;

	count = 0;
	if (!s)
		return (NULL);
	while (s[count] && s[count] != c)
		count++;
	if (!(res = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	count = 0;
	while (*s && *s != c)
	{
		res[count++] = *s;
		s++;
	}
	res[count] = '\0';
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;

	if (!s || !(res = (char **)malloc(sizeof(char *)
					* (count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			if (!(res[j++] = ft_allocateword(s + i, c)))
				return (NULL);
			while (s[i] != c && s[i])
				i++;
		}
	}
	res[j] = NULL;
	return (res);
}
