/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:30:32 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/19 16:19:02 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "grimly.h"
#include <stdio.h>

static void	grim_it(char *file_name)
{
	t_grim *card;

	if (!(card = (t_grim*)ft_memalloc(sizeof(t_grim))))
		return ;
	if (!card_is_valid(file_name, card))
	{
		write(2, "MAP ERROR\n", 10);
		return ;
	}
	find_path(card);	
}

int			main(int ac, char **av)
{
	char *input;

	if (ac > 1)
	{
		av++;
		while (--ac)
		{
			grim_it(*av);
			av++;
		}
	}
	else
	{
		if (!(input = ft_stdin()))
			return (1);
		grim_it(input);
	}
	return (0);
}
