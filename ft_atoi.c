/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:36:07 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/08 18:58:03 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == 9 || c == 10 || c == 11
		|| c == 12 || c == 13 || c == 32);
}

int	ft_atoi(const char *str)
{
	long long	ans;
	long long	sign;

	while (is_space(*str))
		str++;
	ans = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			ans *= 10;
			ans += (*str - '0');
		}
		else
			return ((int)(ans * sign));
		str++;
	}
	return ((int)(ans * sign));
}
