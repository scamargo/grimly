/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:34:27 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/18 15:10:09 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "grimly.h"
#include <fcntl.h>
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

static int	parse_header_symbols(char *header, t_grim *map) //technically you want to check that you have printable characters
{
	if ((map->lines = ft_atoi(header)) <= 0)
		return (0);
	while (*header && *header++ != 'x')
	 	header++;
	if ((map->columns = ft_atoi(header++)) <= 0)
		return (0);
	if ((map->lines * map->columns) > 1000000000)
		return (0);
	while (*header >= '0' && *header <= '9')
		header++;
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
	if (*header != '\n')
		return (0);
	return (1);
}

static char	*read_file(int file_descriptor)
{
	t_array	*buff;
	char	in_buff[30];
	int		reader;
	char	*result;

	if (!(buff = arr_init(30)))
		return (0);
	while ((reader = read(file_descriptor, in_buff, 29)))
	{
		if (reader == -1)
			return (0);
		in_buff[reader] = '\0';
		reader = 0;
		while (in_buff[reader])
			arr_insert(buff, in_buff[reader++]);
	}
	result = buff->str;
	free(buff);
	return (result);
}

int			map_is_valid(char *file_name, t_grim *map)
{
	char	*input;
	int fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (0);
	if (!(input = read_file(fd)))
	{	
		close(fd);
		return (0);
	}
	close(fd);
	if (!parse_header_symbols(input, map))
		return (0);
	if (!no_repeat_symbols(map))
		return (0);
	//if (!(card_is_valid(fd, map)))
	//close(fd);
	return (1);
}
