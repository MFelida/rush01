/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   solve.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: username <your@mail.com>                    +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/06/17 11:54:47 by username     #+#    #+#                  */
/*   Updated: 2025/06/17 13:38:17 by username     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	row_valid(const t_board *board, int row)
{
	int	views[2];
	int	highest[2];
	int	i;

	views[0] = 1;
	highest[0] = board->towers[row * board->side_len];
	views[1] = 1;
	highest[1] = board->towers[((row + 1) * board->side_len) - 1];
	i = 1;
	while (i < board->side_len)
	{
		if (board->towers[(row * board->side_len) + i] > highest[0])
		{
			views[0]++;
			highest[0] = board->towers[(row * board->side_len) + i];
		}
		if (board->towers[((row + 1) * board->side_len) - 1 - i] > highest[1])
		{
			views[1]++;
			highest[1] = board->towers[((row + 1) * board->side_len) - 1 - i];
		}
		i++;
	}
	return (views[0] == board->left[row] && views[1] == board->right[row]);
}

int	col_valid(const t_board *board, int col)
{
	int	views[2];
	int	highest[2];
	int	i;

	views[0] = 1;
	highest[0] = board->towers[col];
	views[1] = 1;
	highest[1] = board->towers[col + board->side_len * (board->side_len - 1)];
	i = 1;
	while (i < board->side_len)
	{
		if (board->towers[col + (i * board->side_len)] > highest[0])
		{
			views[0]++;
			highest[0] = board->towers[col + (i * board->side_len)];
		}
		if (board->towers[col + (board->side_len * (board->side_len - 1 - i ))]
			> highest[1])
		{
			views[1]++;
			highest[1] = board->towers[col + (board->side_len
									* (board->side_len - 1 - i ))];
		}
		i++;
	}
	return (views[0] == board->top[col] && views[1] == board->bot[col]);
}

int	board_solved(t_board *board)
{
	int	i;

	i = -1;
	while (++i < board->side_len)
		if (!row_valid(board, i) || !col_valid(board, i))
			return (0);
	board->state = BOARD_SOLVED;
	return (1);
}

void	_try(t_board	*board, int x, int y)
{
	int i;
	int next_x;
	int next_y;

	i = 1;
	next_x = (x + 1) % board->side_len;
	if (next_x == 0)
		next_y = y + 1;
	while (i <= board->side_len && board->state != BOARD_SOLVED)
	{
		board->towers[y * board->side_len + x] = i;
		if (x == y && x == board->side_len && board_solved(board))
			return ;
		if (next_y < board->side_len)
			_try(board, next_x, next_y);
		i++;
	}
}

void	solve(t_board *board)
{
	_try(board, 0, 0);
}
