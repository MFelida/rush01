/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   strfuncs.c                                        :+:    :+:             */
/*                                                    +:+                     */
/*   By: username <your@mail.com>                    +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/06/17 11:00:44 by username     #+#    #+#                  */
/*   Updated: 2025/06/17 11:29:34 by username     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	ft_isdigit(const char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	res;

	res = ft_strlen(src);
	while (size-- > 1)
		*dest++ = *src++;
	*dest = '\0';
	return (res);
}

char	*ft_strndup(const char *src, const size_t len)
{
	char	*res;

	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, src, len + 1);
	return (res);
}

char	*ft_strchr(const char *str, const char c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *) str);
		str++;
	}
	return (NULL);
}
