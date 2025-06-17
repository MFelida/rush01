/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   get_board.c                                       :+:    :+:             */
/*                                                    +:+                     */
/*   By: username <your@mail.com>                    +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/06/17 11:57:41 by username     #+#    #+#                  */
/*   Updated: 2025/06/17 13:51:24 by username     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include "utils.h"

int	get_board(t_board *board, const char *input)
{
	char	**towers;
	int		(*rule_list)[9];
	int		side_len;
	int		i;

	towers = ft_split(input, WS);
	if (!towers)
		return (1);
	rule_list = &board->top;
	side_len = board->side_len;
	i = 0;
	while (i < (side_len * side_len))
	{
		rule_list[i / side_len][i % side_len] = *(towers[i]) - '0';
		i++;
	}
	ft_free_split(towers);
	return (0);
}
