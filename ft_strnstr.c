/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:30:38 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/08 17:07:35 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	needle_len;

	if (haystack == NULL && len == 0)
		return (NULL);
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	while (*haystack && ((len--) >= needle_len))
	{
		i = 0;
		while (needle[i] == haystack[i])
		{
			i++;
			if (needle[i] == '\0')
				return ((char *)haystack);
			if (haystack[i] == '\0')
				return (NULL);
		}
		haystack++;
	}
	return (NULL);
}
