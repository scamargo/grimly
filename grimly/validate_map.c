/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:34:27 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/17 21:00:27 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "grimly.h"
#include <stdio.h>

static int	no_repeat_symbols(t_grim *map)
{
	if (map->full == map->empty || map->full == map->path ||
		map->full == map->entrance || map->full == map->exit)
		return (0);
	if (map->empty == map->path || map->empty == map->entrance ||
		map->empty == map->exit)
		return (0);
	if (map->path == map->entrance || map->path == map->exit)
		return (0);
	if (map->entrance == map->exit)
		return (0);
	return (1);
}

static int	header_is_valid(char *file_name, t_grim *map)
{
	char	*header;
	//int		file_descriptor;
	
	ft_putendl("made it to header_is_valid");
	ft_putendl(file_name);
	//file_descriptor = open(READ_ONLY);
	//header = get_next_line(file_descriptor);
	header = "31000x31000* o12";
	if ((map->lines = ft_atoi(header)) <= 0)
		return (0);
	while (*header++ != 'x')
	{
		if (!*header)
			return (0);
	}
	if ((map->columns = ft_atoi(header++)) <= 0)
		return (0);
	if ((map->lines * map->columns) > 1000000000)
		return (0);
	while (*header >= '0' && *header <= '9')
		header++;
	printf("lines: %d, col: %d\n", map->lines, map->columns);
	if (!(map->full = *header++))
		return (0);
	if (!(map->empty = *header++))
		return (0);
	if (!(map->path = *header++))
		return (0);
	if (!(map->entrance = *header++))
		return (0);
	if (!(map->exit = *header++))
		return (0);
	if (*header != '\0')
		return (0);
	if (!no_repeat_symbols(map))
		return (0);
	return (1);
}

int			map_is_valid(char *file_name, t_grim *map)
{
	if (!(header_is_valid(file_name, map)))
		return (0);
	return (1);
}
