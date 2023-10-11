/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trusanov <trusanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:55:06 by trusanov          #+#    #+#             */
/*   Updated: 2023/10/11 11:33:37 by trusanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_arr(char **s, char **s_end)
{
	char	**s_it;

	s_it = s;
	while (s_it != s_end)
	{
		free(*s_it);
		s_it++;
	}
	free(s);
}

static char	*get_line(const char *s, char c)
{
	size_t		len;
	char		*res;
	int			index;

	len = 0;
	index = 0;
	while (s[index] && s[index] != c)
	{
		index++;
		len++;
	}
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	index = 0;
	while (s[index] && s[index] != c)
	{
		res[index] = s[index];
		index++;
	}
	return (res);
}

static size_t	get_split_size(char const *s, char c)
{
	size_t	res;

	res = 0;
	while (1)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			return (res);
		res++;
		while (*s && *s != c)
			s++;
	}
}

static char	**one_word_split(char const *s)
{
	char	**ret;
	int		index;

	ret = (char **)malloc(sizeof(char *) * (2));
	if (!ret)
		return (NULL);
	ret[1] = NULL;
	ret[0] = (char *)malloc(ft_strlen(s) + 1);
	if (!ret[0])
	{
		free(ret);
		return (NULL);
	}
	ret[0][ft_strlen(s)] = '\0';
	index = 0;
	while (s[index])
	{
		ret[0][index] = s[index];
		index++;
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	size_t	split_size;
	char	**ret;
	char	**ret_it;

	if (s == NULL || (*s == '\0' && c == '\0'))
		return ((char **)ft_calloc(1, sizeof(char *)));
	if (c == '\0')
		return (one_word_split(s));
	split_size = get_split_size(s, c);
	ret = (char **)malloc(sizeof(char *) * (split_size + 1));
	if (!ret)
		return (NULL);
	ret[split_size] = NULL;
	ret_it = ret;
	while (split_size--)
	{
		while (*s == c)
			s++;
		*ret_it = get_line(s, c);
		if (!*ret_it)
		{
			free_arr(ret, ret_it);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
		ret_it++;
	}
	return (ret);
}
