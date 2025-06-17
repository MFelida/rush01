/* ************************************************************************** */
/*                                                                            */
/*                                                       ::::::::             */
/*   utils.c                                           :+:    :+:             */
/*                                                    +:+                     */
/*   By: username <your@mail.com>                    +#+                      */
/*                                                  +#+                       */
/*   Created: 2025/06/17 11:34:46 by username     #+#    #+#                  */
/*   Updated: 2025/06/17 13:49:46 by username     ########   odam.nl          */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "rush01.h"

#include <stddef.h>
#include <unistd.h>

void	ft_putnbr(const int nbr)
{
	char	c;

	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr(nbr * -1);
		return ;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
}

size_t	ft_putstr(const char *str)
{
	return (write(1, str, ft_strlen(str)));
}
