/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:03:09 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/26 14:17:36 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_put_ch_int(int c)
{
	return (write(1, &c, 1));
}

int	ft_put_ch_ptr(const char *c)
{
	return (write(1, c, 1));
}

int	ft_put_str(const char *s)
{
	if (!s)
		return (write(1, "(null)", ft_strlen("(null)")));
	return (write(1, s, ft_strlen(s)));
}

int	ft_put_percent(void)
{
	return (ft_put_str("%"));
}
