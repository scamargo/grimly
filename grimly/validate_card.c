/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_card.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:09:37 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/21 10:46:49 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "grimly.h"
#include <fcntl.h>
#include <stdio.h>
#define BUFF_SIZE 4096

static int	no_repeat_symbols(t_grim *card)
{
	if (card->full == card->empty || card->full == card->path ||
		card->full == card->entrance || card->full == card->exit)
		return (0);
	if (card->empty == card->path || card->empty == card->entrance ||
		card->empty == card->exit)
		return (0);
	if (card->path == card->entrance || card->path == card->exit)
		return (0);
	if (card->entrance == card->exit)
		return (0);
	return (1);
}

static int	parse_header_symbols(char *header, t_grim *card) //technically you want to check that you have printable characters
{
	int i;
	if ((card->lines = ft_atoi(header)) <= 0)
		return (0);
	i = 0;
	while (header[i] && header[i++] != 'x')
	 	;
	if ((card->columns = ft_atoi(&header[i++])) <= 0)
		return (0);
	if ((card->lines * card->columns) > 1000000000)
		return (0);
	while (header[i] >= '0' && header[i] <= '9')
		i++;
	if (!(card->full = header[i++]))
		return (0);
	if (!(card->empty = header[i++]))
		return (0);
	if (!(card->path = header[i++]))
		return (0);
	if (!(card->entrance = header[i++]))
		return (0);
	if (!(card->exit = header[i++]))
		return (0);
	if (header[i++] != '\n')
		return (0);
	card->size = i + (card->columns + 1) * card->lines;
	return (1);
}

static char	*read_file(int file_descriptor)
{
	t_array	*buff;
	char	in_buff[BUFF_SIZE];
	int		reader;
	char	*result;

	if (!(buff = arr_init(BUFF_SIZE)))
		return (0);
	while ((reader = read(file_descriptor, in_buff, BUFF_SIZE - 1)))
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

int			card_is_valid(char *input_text, t_grim *card, int is_map)
{
	char	*card_text;
	int fd;

	if (is_map)
		fd = 0;
	else if ((fd = open(input_text, O_RDONLY)) == -1)
		return (0);
	if (!(card_text = read_file(fd)))
	{	
		close(fd);
		return (0);
	}
	close(fd);
	if (!parse_header_symbols(card_text, card))
		return (0);
	if (!no_repeat_symbols(card))
		return (0);
	if (!(map_is_valid(card_text, card)))
		return (0);
	return (1);
}
