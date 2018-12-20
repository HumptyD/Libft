/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:14:50 by jlucas-l          #+#    #+#             */
/*   Updated: 2018/12/20 18:08:54 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa_base(long long n, int base, char *type)
{
	char		*res;
	int			len;
	long long 	nb;

	res = NULL;
	if (base >= 2 && base <= 16)
	{
		nb = n;
		len = nb <= 0 ? 1 : 0;
		while (nb)
		{
			nb /= base;
			len++;
		}
		res = ft_strnew(len);
		res[0] = n < 0 ? '-' : res[0];
		while (len--)
		{
			res[len] = (type ? type : "0123456789abcdef")[ABS(n % base)];
			n /= base;
		}
	}
	return (res);
}
