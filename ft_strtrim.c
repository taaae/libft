/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:21:22 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/08 18:59:39 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ch_in_set(char ch, char const *set)
{
	while (*set)
	{
		if (ch == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	char		*resultcp;
	const char	*start;
	const char	*end;

	start = s1;
	while (ch_in_set(*start, set))
		start++;
	end = s1 + ft_strlen(s1);
	if (start == end)
		return ((char *)ft_calloc(1, 1));
	end--;
	while (ch_in_set(*end, set))
		end--;
	result = (char *)malloc(end - start + 2);
	if (!result)
		return (NULL);
	resultcp = result;
	while (start <= end)
		*resultcp++ = *start++;
	*resultcp = '\0';
	return (result);
}
