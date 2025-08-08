// ************************************************************************** //
//                                                                            //
//                                                       ::::::::             //
//   check_utils.c                                     :+:    :+:             //
//                                                    +:+                     //
//   By: mifelida <mifelida@student.email.com>       +#+                      //
//                                                  +#+                       //
//   Created: 2025/08/06 18:29:16 by mifelida     #+#    #+#                  //
//   Updated: 2025/08/06 19:21:55 by mifelida     ########   odam.nl          //
//                                                                            //
// ************************************************************************** //

#include <stddef.h>
#include "rush01.h"

int	check_up(const t_rules *rules, const int board[81], const int col)
{
	int	i;
	int	prev_highest;
	int	res;

	i = col;
	prev_highest = 0;
	res = 0;
	while (i < rules->width * rules->width)
	{
		if (board[i] > prev_highest)
		{
			res++;
			prev_highest = board[i];
		}
		i += rules->width;
	}
	return (res);
}

int	check_down(const t_rules *rules, const int board[81], const int col)
{
	int	i;
	int	prev_highest;
	int	res;

	i = col + rules->width * (rules->width - 1);
	prev_highest = 0;
	res = 0;
	while (i >= 0)
	{
		if (board[i] > prev_highest)
		{
			res++;
			prev_highest = board[i];
		}
		i -= rules->width;
	}
	return (res);
}

int	check_left(const t_rules *rules, const int board[81], const int row)
{
	int	i;
	int	prev_highest;
	int	res;

	i = rules->width * row;
	prev_highest = 0;
	res = 0;
	while (i < (row + 1) * rules->width)
	{
		if (board[i] > prev_highest)
		{
			res++;
			prev_highest = board[i];
		}
		i++;
	}
	return (res);
}

int	check_right(const t_rules *rules, const int board[81], const int row)
{
	int	i;
	int	prev_highest;
	int	res;

	i = (row + 1) * rules->width - 1;
	prev_highest = 0;
	res = 0;
	while (i >= row * rules->width)
	{
		if (board[i] > prev_highest)
		{
			res++;
			prev_highest = board[i];
		}
		i--;
	}
	return (res);
}
