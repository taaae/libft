/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:37:45 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/08 18:58:48 by trusanov         ###   ########.fr       */
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

static void	itoa_on_stack(char res[12], int n)
{
	size_t		len;
	long long	num;

	len = num_len(n);
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
}

void	ft_putnbr_fd(int n, int fd)
{
	char	num[12];

	itoa_on_stack(num, n);
	ft_putstr_fd(num, fd);
}
