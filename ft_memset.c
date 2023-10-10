/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:43:19 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/06 09:33:33 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*b_cp;

	b_cp = (char *)b;
	while (b_cp != b + len)
	{
		*b_cp = (unsigned char)c;
		b_cp++;
	}
	return (b);
}
