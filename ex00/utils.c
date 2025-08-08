// ************************************************************************** //
//                                                                            //
//                                                       ::::::::             //
//   utils.c                                           :+:    :+:             //
//                                                    +:+                     //
//   By: mifelida <mifelida@student.email.com>       +#+                      //
//                                                  +#+                       //
//   Created: 2025/07/30 13:58:46 by mifelida     #+#    #+#                  //
//   Updated: 2025/08/06 19:28:42 by mifelida     ########   odam.nl          //
//                                                                            //
// ************************************************************************** //

#include "rush01.h"

#include <limits.h>
#include <stddef.h>
#include <unistd.h>

int	is_digit(const char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str && ft_strchr("+-", *str))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (is_digit(*str) && res < ((long) INT_MAX + 2))
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	res *= sign;
	if (res < INT_MIN || res > INT_MAX)
		return (0);
	return (res);
}

void	ft_bzero(void *dest, size_t size)
{
	while (size > 0)
		*(unsigned char *)(dest + --size) = 0;
	return ;
}

void	ft_putstr(int fd, const char *str)
{
	write(fd, str, ft_strlen(str));
}

void	print_board(const int board[81], size_t width)
{
	size_t	row;
	size_t	col;
	char	c;

	row = 0;
	while (row < width)
	{
		col = 0;
		while (col < width)
		{
			if (col > 0)
				write(STDOUT_FILENO, " ", 1);
			c = board[col + row * width] + '0';
			write(STDOUT_FILENO, &c, 1);
			col++;
		}
		write(STDOUT_FILENO, "\n", 1);
		row++;
	}
}
