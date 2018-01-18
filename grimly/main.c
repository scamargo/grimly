/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:30:32 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/17 22:03:48 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "grimly.h"
#include <stdio.h>

static void	grim_it(char *file_name)
{
	t_grim *map;

	if (!(map = (t_grim*)ft_memalloc(sizeof(t_grim))))
		return ;
	if (!map_is_valid(file_name, map))
	{
		write(2, "MAP ERROR\n", 10);
		return ;
	}
	ft_putendl("Map valid!");
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
