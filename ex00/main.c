/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   main.c                                            :+:    :+:             */
/*                                                    +:+                     */
/*   By: username <your@mail.com>                    +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/06/17 11:36:59 by username     #+#    #+#                  */
/*   Updated: 2025/06/17 13:50:36 by username     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

#include <stdlib.h>

#define ERROR_MSG "Error\n"

int main(int argc, char *argv[])
{
	t_board	board;

	if (argc != 2)
		return (ft_putstr(ERROR_MSG), EXIT_FAILURE);
	ft_putstr("arg check\n");
	board.side_len = validate_input(argv[1]);
	ft_putstr("validate\n");
	if (board.side_len == 0 || get_board(&board, argv[1]))
		return (ft_putstr(ERROR_MSG), EXIT_FAILURE);
	ft_putstr("get board\n");
	solve(&board);
	ft_putstr("solve\n");
	if (board.state == BOARD_SOLVED)
		print_board(&board);
	else
		return (ft_putstr(ERROR_MSG), EXIT_FAILURE);
	ft_putstr("print\n");
	return (EXIT_SUCCESS);
}
