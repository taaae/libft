/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:47:33 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/12 14:49:26 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	convert_ptr(char *res, unsigned long num)
{
	int	digit;

	digit = num % 16;
	if (digit == 10)
		*res = 'a';
	else if (digit == 11)
		*res = 'b';
	else if (digit == 12)
		*res = 'c';
	else if (digit == 13)
		*res = 'd';
	else if (digit == 14)
		*res = 'e';
	else if (digit == 15)
		*res = 'f';
	else
		*res = digit + '0';
	if (num / 16 != 0)
		convert_ptr(res + 1, num / 16);
	else
		res[1] = '\0';
}

int	ft_put_ptr(const void *p)
{
	char	res[20];

	convert_ptr(res, (unsigned long) p);
	reverse_str(res);
	if (ft_put_str("0x") == -1)
		return (-1);
	return (2 + ft_put_str(res));
	return (0);
}

void	convert_num(char *res, long long num, int notation, int is_lower)
{
	int	digit;

	if (num < 0)
		*res++ = '-';
	if (num < 0)
		num = -num;
	digit = num % notation;
	if (digit == 10)
		*res = 'A' + ' ' * is_lower;
	else if (digit == 11)
		*res = 'B' + ' ' * is_lower;
	else if (digit == 12)
		*res = 'C' + ' ' * is_lower;
	else if (digit == 13)
		*res = 'D' + ' ' * is_lower;
	else if (digit == 14)
		*res = 'E' + ' ' * is_lower;
	else if (digit == 15)
		*res = 'F' + ' ' * is_lower;
	else
		*res = digit + '0';
	if (num / notation != 0)
		convert_num(res + 1, num / notation, notation, is_lower);
	else
		res[1] = '\0';
}

void	reverse_str(char *res)
{
	char	*end;
	char	temp;

	end = res;
	while (*end)
		end++;
	end--;
	if (*res == '-')
		res++;
	while (res < end)
	{
		temp = *end;
		*end = *res;
		*res = temp;
		end--;
		res++;
	}
}
