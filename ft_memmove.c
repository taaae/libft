/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:09:11 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/06 10:35:09 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_cp;

	if (src == dst)
		return (dst);
	dst_cp = (char *)dst;
	if (src > dst)
	{
		while (len--)
		{
			*dst_cp = *(char *)src;
			dst_cp++;
			src++;
		}
	}
	else
	{
		while (len--)
			dst_cp[len] = ((char *)src)[len];
	}
	return (dst);
}
