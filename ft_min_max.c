/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:36:43 by trusanov          #+#    #+#             */
/*   Updated: 2023/11/14 17:37:38 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min(int count, ...)
{
	va_list	args;
	int		res;
	int		current;

	va_start(args, count);
	res = va_arg(args, int);
	while (--count > 0)
	{
		current = va_arg(args, int);
		if (current < res)
			res = current;
	}
	return (res);
}

int	ft_max(int count, ...)
{
	va_list	args;
	int		res;
	int		current;

	va_start(args, count);
	res = va_arg(args, int);
	while (--count > 0)
	{
		current = va_arg(args, int);
		if (current > res)
			res = current;
	}
	return (res);
}
