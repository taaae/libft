/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:09:51 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/09 11:01:47 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	char	*substrcp;

	if (start >= ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof(char)));
	if ((ft_strlen(s) - start) < len)
		substring = (char *)malloc(sizeof(char) * ((ft_strlen(s) - start) + 1));
	else
		substring = (char *)malloc(sizeof(char) * (len + 1));
	if (substring == NULL)
		return (NULL);
	substrcp = substring;
	s += start;
	while (len--)
	{
		*substrcp = *s;
		if (*s == '\0')
			return (substring);
		s++;
		substrcp++;
	}
	*substrcp = '\0';
	return (substring);
}
