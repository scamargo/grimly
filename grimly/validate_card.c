/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_card.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:09:37 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/20 21:44:24 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "grimly.h"
#include <fcntl.h>
#include <stdio.h>

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
	if ((card->lines = ft_atoi(header)) <= 0)
		return (0);
	while (*header && *header++ != 'x')
	 	;
	if ((card->columns = ft_atoi(header++)) <= 0)
		return (0);
	if ((card->lines * card->columns) > 1000000000)
		return (0);
	while (*header >= '0' && *header <= '9')
		header++;
	if (!(card->full = *header++))
		return (0);
	if (!(card->empty = *header++))
		return (0);
	if (!(card->path = *header++))
		return (0);
	if (!(card->entrance = *header++))
		return (0);
	if (!(card->exit = *header++))
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
	//ft_putendl(card_text);
	if (!parse_header_symbols(card_text, card))
		return (0);
	if (!no_repeat_symbols(card))
		return (0);
	if (!(map_is_valid(card_text, card)))
		return (0);
	return (1);
}
