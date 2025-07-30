// ************************************************************************** //
//                                                                            //
//                                                       ::::::::             //
//   rush01.h                                          :+:    :+:             //
//                                                    +:+                     //
//   By: mifelida <mifelida@student.email.com>       +#+                      //
//                                                  +#+                       //
//   Created: 2025/07/30 13:57:26 by mifelida     #+#    #+#                  //
//   Updated: 2025/07/30 15:05:13 by mifelida     ########   odam.nl          //
//                                                                            //
// ************************************************************************** //

#ifndef RUSH01_H
# define RUSH01_H

# include <stddef.h>

int		get_board(int *board, const char *input);
size_t	ft_strlen(const char *str);
char	*ft_strndup(const char *src, const int n);
char	*ft_strchr(const char *str, const char c);
size_t	ft_strlcpy(const char *src, char *dest, size_t l);
int		ft_atoi(const char *str);

char	**ft_split(const char *str, const char *ws);
void	ft_split_free(char **split);

#endif // RUSH01_H
