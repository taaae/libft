/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:56:02 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/26 14:20:01 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

void	convert_num(char *res, long long num, int notation, int is_lower);
void	reverse_str(char *res);

int		ft_put_ch_int(int c);
int		ft_put_ch_ptr(const char *c);
int		ft_put_str(const char *s);
int		ft_put_ptr(const void *p);
int		ft_put_int(int i);
int		ft_put_uint(unsigned int i);
int		ft_put_hex_lower(unsigned int i);
int		ft_put_hex_upper(unsigned int i);
int		ft_put_percent(void);

#endif
