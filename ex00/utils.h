/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   utils.h                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: username <your@mail.com>                    +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/06/17 11:01:35 by username     #+#    #+#                  */
/*   Updated: 2025/06/17 12:16:22 by username     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "rush01.h"

# include <stddef.h>

# define WS "\t\n\v\f\r "

int		ft_isdigit(const char c);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strndup(const char *src, const size_t len);
char	*ft_strchr(const char *str, const char c);
char	**ft_split(const char *str, const char *delims);
char	**ft_free_split(char **split);

#endif // !UTILS_H

