/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlucas-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:21:53 by jlucas-l          #+#    #+#             */
/*   Updated: 2018/11/27 17:34:21 by jlucas-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freelst(t_list *lst)
{
	t_list *nobj;

	while (lst)
	{
		nobj = lst->next;
		free(lst->content);
		free(lst);
		lst = nobj;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*obj;
	t_list	*temp;

	obj = NULL;
	temp = NULL;
	if (lst && f)
	{
		if (!(obj = f(lst)))
			return (NULL);
		temp = obj;
		while (lst->next)
		{
			lst = lst->next;
			if (!(temp->next = f(lst)))
			{
				ft_freelst(obj);
				return (NULL);
			}
			temp = temp->next;
		}
	}
	return (obj);
}
