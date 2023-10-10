/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:36:07 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/08 15:13:24 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	res;

	res = ft_strlen(src);
	if (dstsize == 0)
		return (res);
	dstsize--;
	while (*src && dstsize--)
		*dst++ = *src++;
	*dst = '\0';
	return (res);
}
