/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:59:06 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/11 18:07:51 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	i;

	if (count != 0 && size != 0 && count > ((size_t) - 1) / size)
		return (NULL);
	res = malloc(count * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		((char *)res)[i] = '\0';
		i++;
	}
	return (res);
}
