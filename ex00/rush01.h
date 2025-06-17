/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   rush01.h                                          :+:    :+:             */
/*                                                    +:+                     */
/*   By: username <your@mail.com>                    +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/06/17 09:40:43 by username     #+#    #+#                  */
/*   Updated: 2025/06/17 13:52:02 by username     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stddef.h>

typedef enum e_board_state
{
	BOARD_UNSOLVED,
	BOARD_SOLVED,
}	t_board_state;

typedef struct s_board
{
	int				top[9];
	int				bot[9];
	int				left[9];
	int				right[9];
	int				side_len;
	int				towers[81];
	t_board_state	state;
}	t_board;

int		get_board(t_board *board, const char *input);
void	solve(t_board *board);
int		board_solved(t_board *board);
void	print_board(const t_board *board);

size_t	ft_putstr(const char *str);
void	ft_putnbr(int nbr);
int		validate_input(const char *input);

#endif // !RUSH01_H
