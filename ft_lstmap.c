/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:21:53 by jlucas-l          #+#    #+#             */
/*   Updated: 2018/11/26 18:13:55 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*obj;
	t_list	*temp;

	obj = NULL;
	temp = NULL;
	if (lst && f)
	{
		obj = f(lst);
		temp = obj;
		while (lst->next)
		{
			lst = lst->next;
			if (!(temp->next = f(lst)))
				return (NULL);
			temp = temp->next;
		}
	}
	return (obj);
}
