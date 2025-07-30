// ************************************************************************** //
//                                                                            //
//                                                       ::::::::             //
//   str_utils.c                                       :+:    :+:             //
//                                                    +:+                     //
//   By: mifelida <mifelida@student.email.com>       +#+                      //
//                                                  +#+                       //
//   Created: 2025/07/30 14:27:01 by mifelida     #+#    #+#                  //
//   Updated: 2025/07/30 14:29:24 by mifelida     ########   odam.nl          //
//                                                                            //
// ************************************************************************** //


#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	res;

	res = 0;
	while (*str++)
		res++;
	return (res);
}
size_t	ft_strlcpy(const char *src, char *dest, size_t l)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = (const unsigned char *) src;
	d = (unsigned char *) dest;
	while (l > 1)
		*d++ = *s++;
	*d = '\0';
	return (ft_strlen(src));
}

char	*ft_strndup(const char *src, const int n)
{
	char	*res;

	if (src == NULL)
		return (NULL);
	res = malloc(n + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(src, res, n + 1);
	return (res);
}

char	*ft_strchr(const char *str, const char c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return ((char *) str);
		str++;
	}
	return (NULL);
}
