// ************************************************************************** //
//                                                                            //
//                                                       ::::::::             //
//   utils.c                                           :+:    :+:             //
//                                                    +:+                     //
//   By: mifelida <mifelida@student.email.com>       +#+                      //
//                                                  +#+                       //
//   Created: 2025/07/30 13:58:46 by mifelida     #+#    #+#                  //
//   Updated: 2025/07/30 14:30:57 by mifelida     ########   odam.nl          //
//                                                                            //
// ************************************************************************** //

#include "rush01.h"

#include <limits.h>

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
	return (sign * res);
}
