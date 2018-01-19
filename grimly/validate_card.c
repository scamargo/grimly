/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_card.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:14:39 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/18 18:52:55 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "libft.h"

static int	is_valid_char(char c, t_grim *map, int x, int y, int *p_entries, int *p_exits)
{
	if (c == map->full)
		return (1);
	if (c == map->empty)
		return (1);
	if (c == map->entrance)
	{
		map->entrance_pos[0] = x;
		map->entrance_pos[1] = y;
		if (++(*p_entries) > 1)
			return (0);
		return (1);
	}
	if (c == map->exit)
	{
		++(*p_exits);
		return (1);
	}
	return (0);
}

int	card_is_valid(char *input, t_grim *map)
{
	int lines;
	int columns;
	int i;
	int entries;
	int exits;

	while (*input++ != '\n')
		;
	i = 0;
	lines = 0;
	entries = 0;
	exits = 0;
	while (input[i])
	{
		columns = 0;
		while (input[i] && input[i] != '\n')
		{
			if (!is_valid_char(input[i], map, columns, lines, &entries, &exits))
				return (0);
			columns++;
			i++;
		}
		if (columns != map->columns)
			return (0);
		lines++;
		i++;
	}
	if (lines != map->lines || entries < 1 || exits < 1)
		return (0);
	return (1);
}
