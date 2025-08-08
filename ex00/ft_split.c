// ************************************************************************** //
//                                                                            //
//                                                       ::::::::             //
//   ft_split.c                                        :+:    :+:             //
//                                                    +:+                     //
//   By: mifelida <mifelida@student.email.com>       +#+                      //
//                                                  +#+                       //
//   Created: 2025/07/30 14:17:22 by mifelida     #+#    #+#                  //
//   Updated: 2025/08/06 19:32:40 by mifelida     ########   odam.nl          //
//                                                                            //
// ************************************************************************** //

#include "rush01.h"

#include <stddef.h>
#include <stdlib.h>

static size_t	_word_len(const char *str, const char *ws)
{
	size_t	res;

	res = 0;
	while (str[res] != '\0' && !ft_strchr(ws, str[res]))
		res++;
	return (res);
}

static char	*_skip_ws(const char *str, const char *ws)
{
	while (ft_strchr(ws, *str))
		str++;
	return ((char *) str);
}

static size_t	_count_words(const char *str, const char *ws)
{
	size_t	res;

	res = 0;
	str = _skip_ws(str, ws);
	while (*str != '\0')
	{
		res++;
		str += _word_len(str, ws);
		str = _skip_ws(str, ws);
	}
	return (res);
}

void	ft_split_free(char **split)
{
	size_t	i;

	if (split == NULL)
		return ;
	i = 0;
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
}

char	**ft_split(const char *str, const char *ws)
{
	char	**res;
	char	**temp;

	if (str == NULL)
		return (NULL);
	res = malloc((_count_words(str, ws) + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	temp = res;
	str = _skip_ws(str, ws);
	while (*str != '\0')
	{
		*temp = ft_strndup(str, _word_len(str, ws) + 1);
		if (*temp == NULL)
		{
			ft_split_free(res);
			return (NULL);
		}
		temp++;
		str += _word_len(str, ws);
		str = _skip_ws(str, ws);
	}
	*temp = NULL;
	return (res);
}
