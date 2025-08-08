// ************************************************************************** //
//                                                                            //
//                                                       ::::::::             //
//   rush01.h                                          :+:    :+:             //
//                                                    +:+                     //
//   By: mifelida <mifelida@student.email.com>       +#+                      //
//                                                  +#+                       //
//   Created: 2025/07/30 13:57:26 by mifelida     #+#    #+#                  //
//   Updated: 2025/08/06 19:26:26 by mifelida     ########   odam.nl          //
//                                                                            //
// ************************************************************************** //

#ifndef RUSH01_H
# define RUSH01_H

# include <stddef.h>

typedef struct s_rules
{
	int	top[9];
	int	bot[9];
	int	left[9];
	int	right[9];
	int	width;
}	t_rules;

int		get_rules(t_rules *rules, const char *input);
int		solve(const t_rules *rules, int board[81], int idx);
void	print_board(const int board[81], size_t width);

size_t	ft_strlen(const char *str);
char	*ft_strndup(const char *src, const int n);
char	*ft_strchr(const char *str, const char c);
size_t	ft_strlcpy(const char *src, char *dest, size_t l);
int		ft_atoi(const char *str);
void	ft_bzero(void *dest, size_t size);
void	ft_putstr(int fd, const char *str);

char	**ft_split(const char *str, const char *ws);
void	ft_split_free(char **split);

#endif // RUSH01_H
