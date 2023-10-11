/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:00:48 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/11 11:54:23 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*norminette_sucks(void (*del)(void *), t_list *content_temp)
{
	del(content_temp);
	return (NULL);
}

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
		return (norminette_sucks(del, content_temp));
	lst = lst->next;
	ret_it = ret;
	while (lst)
	{
		content_temp = f(lst->content);
		ret_it->next = ft_lstnew(content_temp);
		if (!ret_it->next)
		{
			ft_lstclear(&ret, del);
			return (norminette_sucks(del, content_temp));
		}
		lst = lst->next;
		ret_it = ret_it->next;
	}
	return (ret);
}
