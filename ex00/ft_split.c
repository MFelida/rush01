/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   ft_split.c                                        :+:    :+:             */
/*                                                    +:+                     */
/*   By: username <your@mail.com>                    +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/06/17 09:29:51 by username     #+#    #+#                  */
/*   Updated: 2025/06/17 14:04:16 by username     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

char	*_skip_ws(const char *str, const char *ws)
{
	while (*str && ft_strchr(ws, *str))
		str++;
	return ((char *)str);
}

size_t	_word_len(const char *str, const char *delims)
{
	size_t	i;

	i = 0;
	while (str[i] && !ft_strchr(delims, str[i]))
		i++;
	return (i);
}

size_t	_word_count(const char *src, const char *delims)
{
	size_t	res;

	res = 0;
	while (*src)
	{
		src = _skip_ws(src, delims);
		if (*src)
			res++;
		src += _word_len(src, delims);
	}
	return (res);
}

char	**ft_free_split(char **split)
{
	char	**temp;
	
	temp = split;
	while (*temp)
		free(*temp++);
	free(split);
	return (NULL);
}

char **ft_split(const char *src, const char *delims)
{
	char	**res;
	char	**temp;
	size_t	n_words;
	size_t	len;

	if (!src)
		return (NULL);
	n_words = _word_count(src, delims);
	res = malloc((n_words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	temp = res;
	while (n_words-- > 0)
	{
		src = _skip_ws(src, delims);
		len = _word_len(src, delims);
		*temp = ft_strndup(src, len);
		if (!*temp)
			return (ft_free_split(res));
		src += len;
		temp++;
	}
	*temp = NULL;
	return (res);
}
