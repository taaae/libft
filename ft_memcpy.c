/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:37:45 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/08 17:32:01 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_cp;

	if (!dst && !src)
		return (NULL);
	dst_cp = (char *)dst;
	while (dst_cp != dst + n)
	{
		*dst_cp = *(char *)src;
		src++;
		dst_cp++;
	}
	return (dst);
}
