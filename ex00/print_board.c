/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   print_board.c                                     :+:    :+:             */
/*                                                    +:+                     */
/*   By: username <your@mail.com>                    +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/06/17 12:22:01 by username     #+#    #+#                  */
/*   Updated: 2025/06/17 12:25:16 by username     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */


#include "rush01.h"

#include <stddef.h>

void	print_board(const t_board *board)
{
	int	i;
	int j;

	j = 0;
	while (j < board->side_len)
	{
		i = 0;
		while (i < board->side_len)
		{
			ft_putnbr(board->towers[j * board->side_len + i++]);
			if (i % board->side_len < board->side_len - 1)
				ft_putstr(" ");
		}
		ft_putstr("\n");
		j++;
	}
}
