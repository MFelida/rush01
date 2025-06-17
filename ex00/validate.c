/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   validate.c                                        :+:    :+:             */
/*                                                    +:+                     */
/*   By: username <your@mail.com>                    +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/06/17 11:00:18 by username     #+#    #+#                  */
/*   Updated: 2025/06/17 13:57:19 by username     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include <stddef.h>

int	validate_input(const char *input)
{
	int		n_numbers;
	size_t	i;

	n_numbers = 0;
	i = 0;
	while (input[i])
	{
		while (input[i] && ft_strchr(WS, input[i]))
			i++;
		if (!input[i])
			break;
		if (!ft_isdigit(input[i]) || input[i] == '0'
			|| (input[i + 1] && !ft_strchr(WS, input[i + 1])))
			return (0);
		n_numbers++;
		i++;
	}
	if (n_numbers > 81)
		return (0);
	i = 3;
	while (++i < 10)
		if (n_numbers == i * i)
			return (i);
	return (0);
}
