/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:33:15 by jlucas-l          #+#    #+#             */
/*   Updated: 2018/11/28 15:02:38 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;

	if (size == (size_t)(-1))
		return (0);
	if (!(res = (char *)ft_memalloc(size + 1)))
		return (NULL);
	return (res);
}
