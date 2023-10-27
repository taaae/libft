/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:12:25 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/27 15:43:15 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	move_chars(char buffer[BUFFER_SIZE], int index);
static char	*norme_sucks(t_line ans, char buffer[BUFFER_SIZE], int bytes_read);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	t_line		ans;
	int			index;

	ans = new_line(&index);
	if (index)
		return (NULL);
	while (1)
	{
		index = 0;
		while (index < BUFFER_SIZE && buffer[index])
		{
			if (line_push(&ans, buffer[index]) == 1)
				return (NULL);
			if (buffer[index++] == '\n' && line_push(&ans, '\0') != 42)
			{
				move_chars(buffer, index);
				return (ans.buf);
			}
		}
		ft_bzero(buffer, BUFFER_SIZE);
		index = read(fd, buffer, BUFFER_SIZE);
		if (index == 0 || index == -1)
			return (norme_sucks(ans, buffer, index));
	}
}

static void	move_chars(char buffer[BUFFER_SIZE], int index)
{
	int	i;

	i = 0;
	while ((index < BUFFER_SIZE) && buffer[index])
		buffer[i++] = buffer[index++];
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
}

t_line	new_line(int *malloc_signal)
{
	t_line	res;

	res.len = 0;
	res.cap = LINE_INITIAL_CAP;
	res.buf = (char *)malloc(sizeof(char) * res.cap);
	if (!res.buf)
		*malloc_signal = 1;
	else
		*malloc_signal = 0;
	return (res);
}

int	line_push(t_line *line, char c)
{
	char		*new_buf;
	size_t		i;

	if (line->len == line->cap)
	{
		new_buf = (char *)malloc(sizeof(char) * line->cap * 2);
		if (!new_buf)
		{
			free(line->buf);
			line->buf = NULL;
			return (1);
		}
		i = 0;
		while (i < line->len)
		{
			new_buf[i] = line->buf[i];
			i++;
		}
		free(line->buf);
		line->buf = new_buf;
		line->cap *= 2;
	}
	line->buf[line->len] = c;
	line->len++;
	return (0);
}

static char	*norme_sucks(t_line ans, char buffer[BUFFER_SIZE], int bytes_read)
{
	if (bytes_read == -1)
	{
		free(ans.buf);
		return (NULL);
	}
	if (bytes_read == 0)
	{
		ft_bzero(buffer, BUFFER_SIZE);
		if (ans.len == 0)
		{
			free(ans.buf);
			return (NULL);
		}
		if (line_push(&ans, '\0') == 1)
			return (NULL);
		return (ans.buf);
	}
	return (NULL);
}
