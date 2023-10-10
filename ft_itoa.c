/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:39:36 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/08 18:50:19 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(int n)
{
	size_t	res;

	res = (n <= 0);
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char		*res;
	size_t		len;
	long long	num;

	len = num_len(n);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	num = n;
	if (num < 0)
	{
		res[0] = '-';
		num *= -1;
	}
	if (num == 0)
		res[0] = '0';
	while (num)
	{
		res[len - 1] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (res);
}
