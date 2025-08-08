// ************************************************************************** //
//                                                                            //
//                                                       ::::::::             //
//   get_rules.c                                       :+:    :+:             //
//                                                    +:+                     //
//   By: mifelida <mifelida@student.email.com>       +#+                      //
//                                                  +#+                       //
//   Created: 2025/07/30 15:01:32 by mifelida     #+#    #+#                  //
//   Updated: 2025/08/06 19:21:03 by mifelida     ########   odam.nl          //
//                                                                            //
// ************************************************************************** //

#include <stddef.h>
#include "rush01.h"

static int	_get_width(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		i++;
	if (i % 4 != 0)
		return (0);
	return (i / 4);
}
int	get_rules(t_rules *rules, const char *input)
{
	char	**split;
	int		i;

	split = ft_split(input, " ");
	if (split == NULL)
		return (0);
	rules->width = _get_width(split);
	if (rules->width < 1)
		return (0);
	i = 0;
	while (split[i])
	{
		if (i < rules->width)
			rules->top[i] = ft_atoi(split[i]);
		else if (i < rules->width * 2)
			rules->bot[i - rules->width] = ft_atoi(split[i]);
		else if (i < rules->width * 3)
			rules->left[i - 2 * rules->width] = ft_atoi(split[i]);
		else
			rules->right[i - 3 * rules->width] = ft_atoi(split[i]);
		i++;
	}
	ft_split_free(split);
	return (rules->width);
}
