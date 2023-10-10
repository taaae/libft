/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:00:48 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/10 19:53:53 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*ret_it;
	t_list	*content_temp;

	if (lst == NULL || f == NULL)
		return (NULL);
	content_temp = f(lst->content);
	ret = ft_lstnew(content_temp);
	if (!ret)
	{
		del(content_temp);
		return (NULL);
	}
	lst = lst->next;
	ret_it = ret;
	while (lst)
	{
		content_temp = f(lst->content);
		ret_it->next = ft_lstnew(content_temp);
		if (!ret_it->next)
		{
			del(content_temp);
			ft_lstclear(&ret, del);
			return (NULL);
		}
		lst = lst->next;
		ret_it = ret_it->next;
	}
	return (ret);
}
