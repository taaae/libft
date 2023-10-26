/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:17:55 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/12 14:51:38 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_percent(const char *str, va_list args);

int	ft_printf(const char *str, ...)
{
	int		res;
	int		write_ret;
	va_list	args;

	va_start(args, str);
	res = 0;
	while (*str)
	{
		if (*str != '%')
			write_ret = ft_put_ch_ptr(str);
		else
			write_ret = handle_percent(++str, args);
		if (write_ret == -1)
			return (-1);
		res += write_ret;
		str++;
	}
	va_end(args);
	return (res);
}

static int	handle_percent(const char *str, va_list args)
{
	if (*str == 'c')
		return (ft_put_ch_int(va_arg(args, int)));
	if (*str == 's')
		return (ft_put_str(va_arg(args, char *)));
	if (*str == 'p')
		return (ft_put_ptr(va_arg(args, void *)));
	if (*str == 'd' || *str == 'i')
		return (ft_put_int(va_arg(args, int)));
	if (*str == 'u')
		return (ft_put_uint(va_arg(args, unsigned int)));
	if (*str == 'x')
		return (ft_put_hex_lower(va_arg(args, unsigned int)));
	if (*str == 'X')
		return (ft_put_hex_upper(va_arg(args, unsigned int)));
	if (*str == '%')
		return (ft_put_percent());
	return (-1);
}
