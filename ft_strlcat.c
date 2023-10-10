/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:56 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/08 17:00:27 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;

	if (dst == NULL && dstsize == 0)
		return (0);
	if (ft_strlen(dst) <= dstsize)
		ret = ft_strlen(src) + ft_strlen(dst);
	else
		ret = ft_strlen(src) + dstsize;
	if (dstsize == 0)
		return (ret);
	while (*dst && dstsize)
	{
		dstsize--;
		dst++;
	}
	if (dstsize == 0)
		return (ret);
	while (*src && --dstsize)
		*dst++ = *src++;
	*dst = '\0';
	return (ret);
}
