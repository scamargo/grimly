/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:10:05 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/20 18:41:48 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "libft.h"

static int	is_valid_char(char c, t_grim *map)
{
	if (c == map->full)
		return (1);
	if (c == map->empty)
		return (1);
	if (c == map->entrance)
		return (1);
	if (c == map->exit)
		return (1);
	return (0);
}

static int	map_meets_reqs(int en, int ex, int li, t_grim *card)
{
	if (li != card->lines)
		return (0);
	if (en < 1)
		return (0);
	if (ex < 1)
		return (0);
	return (1);
}

int			map_is_valid(char *input, t_grim *card)
{
	int lines;
	int columns;
	int entries;
	int exits;
	int i;
	
	card->card = input;
	while (*input++ != '\n')
		;
	lines = 0;
	entries = 0;
	exits = 0;
	i = 0;
	card->map = input;
	while (input[i])
	{
		columns = 0;
		while (input[i] && input[i] != '\n')
		{
			if (input[i] == card->entrance)
			{
				card->entrance_pos = i;
				entries++;
			}
			else if (input[i] == card->exit)
				exits++;
			if (!is_valid_char(input[i++], card))
				return (0);
			columns++;
		}
		if (columns != card->columns)
			return (0);
		lines++;
		i++;
	}
	if (!map_meets_reqs(entries, exits, lines, card))
		return (0);
	return (1);
}
