/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:16:07 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/09 10:52:04 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	c = c % 256;
	res = NULL;
	while (*s)
	{
		if (*s == c)
			res = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *) s);
	return (res);
}
