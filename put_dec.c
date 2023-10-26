/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:04:58 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/12 14:49:56 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_int(int i)
{
	char	res[12];

	convert_num(res, i, 10, 0);
	reverse_str(res);
	return (ft_put_str(res));
}

int	ft_put_uint(unsigned int i)
{
	char	res[12];

	convert_num(res, i, 10, 0);
	reverse_str(res);
	return (ft_put_str(res));
}

int	ft_put_hex_lower(unsigned int i)
{
	char	res[12];

	convert_num(res, i, 16, 1);
	reverse_str(res);
	return (ft_put_str(res));
}

int	ft_put_hex_upper(unsigned int i)
{
	char	res[12];

	convert_num(res, i, 16, 0);
	reverse_str(res);
	return (ft_put_str(res));
}
