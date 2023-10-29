/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tae <tae@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:28:36 by tae               #+#    #+#             */
/*   Updated: 2023/10/29 15:28:37 by tae              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_string	*tstring_grow(t_string *this);

/// @return returns pointer to new t_string, NULL if allocation fails
t_string	*tstring_new(void)
{
	t_string	*this;

	this = (t_string *)malloc(sizeof(t_string));
	if (!this)
		return (NULL);
	this->cap = INIT_TSTRING_CAP;
	this->size = 0;
	this->buf = (char *)malloc(INIT_TSTRING_CAP * sizeof(char));
	if (!this->buf)
	{
		free(this);
		return (NULL);
	}
	return (this);
}

/// @brief frees tstring and its buffer
/// @param this pointer to tstring
void	tstring_free(t_string *this)
{
	if (!this)
		return ;
	free(this->buf);
	free(this);
}

/// @brief appends one char to the end
/// @param this pointer to t_string
/// @param c character to push
/// @return this. NULL if allocation fails [also frees this]
void	*tstring_push_back(t_string *this, char c)
{
	if (!this)
		return (NULL);
	if (this->size == this->cap)
		if (tstring_grow(this) == NULL)
			return (NULL);
	this->buf[this->size++] = c;
	return (this);
}

/// @brief swap pointers
/// @param first first ptr to ptr, shouldn't be NULL
/// @param second second ptr to ptr, shouldn't be NULL
static void	buf_swap(char **first, char **second)
{
	void	*tmp;

	tmp = *first;
	*first = *second;
	*second = tmp;
}

/// @brief doubles t_sring capacity, moves to a new buffer
/// @param this pointer to t_string
/// @return this. NULL if allocation fails [also frees this]
static t_string	*tstring_grow(t_string *this)
{
	char	*new_buf;
	size_t	index;

	if (!this)
		return (NULL);
	new_buf = (char *)malloc(this->cap * 2 * sizeof(char));
	if (!new_buf)
	{
		tstring_free(this);
		return (NULL);
	}
	index = 0;
	while (index < this->size)
	{
		new_buf[index] = this->buf[index];
		index++;
	}
	buf_swap(&this->buf, &new_buf);
	free(new_buf);
	this->cap *= 2;
	return (this);
}
