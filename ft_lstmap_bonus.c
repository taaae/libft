/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:00:48 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/10 12:58:12 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*ret_it;

	if (lst == NULL || f == NULL)
		return (NULL);
	ret = ft_lstnew(f(lst->content));
	lst = lst->next;
	if (!ret)
		return (NULL);
	ret_it = ret;
	while (lst)
	{
		ret_it->next = ft_lstnew(f(lst->content));
		if (!ret_it)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		lst = lst->next;
		ret_it = ret_it->next;
	}
	return (ret);
}
