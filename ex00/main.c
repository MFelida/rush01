// ************************************************************************** //
//                                                                            //
//                                                       ::::::::             //
//   main.c                                            :+:    :+:             //
//                                                    +:+                     //
//   By: mifelida <mifelida@student.email.com>       +#+                      //
//                                                  +#+                       //
//   Created: 2025/07/30 14:15:35 by mifelida     #+#    #+#                  //
//   Updated: 2025/08/06 19:21:08 by mifelida     ########   odam.nl          //
//                                                                            //
// ************************************************************************** //

#include "rush01.h"

#include <stdlib.h>
#include <unistd.h>

int	main(int argc, const char *argv[])
{
	t_rules	rules;
	int		board[81];

	if (argc != 2 || get_rules(&rules, argv[1]) < 1)
	{
		ft_putstr(STDERR_FILENO, "Error\n");
		return (EXIT_FAILURE);
	}
	if (solve(&rules, board, 0))
		print_board(board, rules.width);
	else
	{
		ft_putstr(STDERR_FILENO, "Error\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
