/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:46:20 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/07 12:19:47 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	char	*copy_start;

	copy = (char *)malloc(ft_strlen(src) + 1);
	if (!copy)
		return (NULL);
	copy_start = copy;
	while (*src != '\0')
	{
		*copy = *src;
		copy++;
		src++;
	}
	*copy = '\0';
	return (copy_start);
}
