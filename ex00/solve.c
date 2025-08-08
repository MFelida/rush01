// ************************************************************************** //
//                                                                            //
//                                                       ::::::::             //
//   solve.c                                           :+:    :+:             //
//                                                    +:+                     //
//   By: mifelida <mifelida@student.codam.nl>        +#+                      //
//                                                  +#+                       //
//   Created: 2025/08/06 18:31:16 by mifelida     #+#    #+#                  //
//   Updated: 2025/08/06 19:24:41 by mifelida     ########   odam.nl          //
//                                                                            //
// ************************************************************************** //

#include <stddef.h>
#include "rush01.h"

int	check_up(const t_rules *rules, const int board[81], const int col);
int	check_down(const t_rules *rules, const int board[81], const int col);
int	check_left(const t_rules *rules, const int board[81], const int row);
int	check_right(const t_rules *rules, const int board[81], const int row);

static int	column_solved(const t_rules *rules, const int board[81],
						const int col)
{
	if (col >= rules->width)
		return (0);
	if (check_up(rules, board, col) != rules->top[col])
		return (0);
	if (check_down(rules, board, col) != rules->bot[col])
		return (0);
	return (1);
}

static int	row_solved(const t_rules *rules, const int board[81], const int row)
{
	if (check_left(rules, board, row) != rules->left[row]) return (0);
	if (check_right(rules, board, row) != rules->right[row]) return (0);
	return (1);
}

static int	_valid_height(const t_rules *rules, const int board[81],
						const int idx, const int height)
{
	int	j;
	int	row;
	int	col;

	j = 0;
	row = idx / rules->width;
	col = idx % rules->width;
	while (j < row || j < col)
	{
		if ((j < col && height == board[j + row * rules->width])
			|| (j < row && height == board[col + j * rules->width]))
			return (0);
		j++;
	}
	return (1);
}

int	is_solved(const t_rules *rules, const int board[81])
{
	int	i;

	i = 0;
	while (i < rules->width)
	{
		if (!column_solved(rules, board, i))
			return (0);
		if (!row_solved(rules, board, i))
			return (0);
		i++;
	}
	return (1);
}

int	solve(const t_rules *rules, int board[81], int idx)
{
	int	i;

	if (idx >= rules->width * rules->width)
		return (is_solved(rules, board));
	i = 1;
	while (i <= rules->width)
	{
		if (!_valid_height(rules, board, idx, i))
		{
			i++;
			continue ;
		}
		board[idx] = i;
		if (solve(rules, board, idx + 1))
			return (1);
		i++;
	}
	return (0);
}
