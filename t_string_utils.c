/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae <tae@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:28:26 by tae               #+#    #+#             */
/*   Updated: 2023/10/29 15:28:28 by tae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief prints content of tstring with a terminating newline
/// @param this pointer to tstring
void	tstring_print(const t_string *this)
{
	if (!this)
	{
		write(1, "(NULL)\n", 7);
		return ;
	}
	write(1, this->buf, this->size);
	write(1, "\n", 1);
}

/// @brief pops character from the end and returns it. 
/// Exits program if string is empty or is NULL.
/// @param this pointer to tstring
/// @return 
char	tstring_pop_back(t_string *this)
{
	if (!this || this->size == 0)
	{
		write(1, "tstring_pop_back failure\n", 25);
		exit(1);
	}
	return (this->buf[--this->size]);
}
