/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_card.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:14:39 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/19 10:02:41 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "libft.h"

static int	is_valid_char(char c, t_grim *map, int x, int y, int *p_en, int *p_ex)
{
	if (c == map->full)
		return (1);
	if (c == map->empty)
		return (1);
	if (c == map->entrance)
	{
		map->entrance_pos[0] = x;
		map->entrance_pos[1] = y;
		if (++(*p_en) > 1)
			return (0);
		return (1);
	}
	if (c == map->exit)
	{
		++(*p_ex);
		return (1);
	}
	return (0);
}

static int	card_meets_reqs(int en, int ex, int li, t_grim *map)
{
	if (li != map->lines)
		return (0);
	if (en < 1)
		return (0);
	if (ex < 1)
		return (0);
	return (1);
}

int			card_is_valid(char *input, t_grim *map)
{
	int lines;
	int columns;
	int entries;
	int exits;

	while (*input++ != '\n')
		;
	lines = 0;
	entries = 0;
	exits = 0;
	while (*input)
	{
		columns = 0;
		while (*input && *input != '\n')
		{
			if (!is_valid_char(*input++, map, columns, lines, &entries, &exits))
				return (0);
			columns++;
		}
		if (columns != map->columns)
			return (0);
		lines++;
		input++;
	}
	if (!card_meets_reqs(entries, exits, lines, map))
		return (0);
	return (1);
}
