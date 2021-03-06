/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:00:27 by jlucas-l          #+#    #+#             */
/*   Updated: 2018/11/25 16:43:14 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (n == 0)
		return (s1);
	i = 0;
	j = -1;
	while (s1[i])
		i++;
	while (s2[++j] && j < n)
		s1[i + j] = s2[j];
	s1[i + j] = '\0';
	return (s1);
}
