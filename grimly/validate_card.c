/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_card.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 14:14:39 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/18 14:36:29 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grimly.h"
#include "libft.h"

static char	*read_file(int fd) //TODO: use map length to determine reading size -- may speed things up
{
	t_array	*char_arr;
	char	in_buff[50];
	char	*result;
	int		reader;

	if (!(char_arr = arr_init(50)))
		return (0);
	while ((reader = read(fd, in_buff, 49)))
	{
		if (reader == -1)
			return (0);
		reader = 0;
		while (in_buff[reader])
			arr_insert(char_arr, in_buff[reader++]);
	}
	result = char_arr->str;
	free(char_arr);
	return (result);
}

int	card_is_valid(int fd, t_grim *map)
{
	//read & print map
	char	*input;

	if (!(input = read_file(fd)))
		return (0);
	ft_putstr(input);
	if (0)
		ft_putchar(map->full);
	//if(!(map->card = read_card(fd)))
	//	return (0);
	//check that lines & cols match key
	//check for bad chars
	//check for min one entrance
	//check for min one exit
	return (1);
}
