/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:11:25 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/08 14:05:53 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*resultit;

	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	resultit = result;
	while (*s1)
	{
		*resultit = *s1;
		s1++;
		resultit++;
	}
	while (*s2)
	{
		*resultit = *s2;
		s2++;
		resultit++;
	}
	*resultit = '\0';
	return (result);
}
