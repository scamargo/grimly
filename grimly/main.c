/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:30:32 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/17 20:09:23 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "grimly.h"
#include <stdio.h>

static void	grim_it(char *file_name)
{
	t_grim *map;

	if(!(map = (t_grim*)ft_memalloc(sizeof(t_grim))))
		exit(1);
	if (!map_is_valid(file_name, map))
	{
		ft_putendl("MAP ERROR");
		return ;
	}
	printf("map lines: %d\n", map->lines);
	ft_putendl("Map valid!");
}

int	main(int ac, char **av)
{
	char *input;
	// read arguments, else read from stdin
	if (ac > 1)
	{
		av++;
		while (--ac)
		{
			printf("av grim it: %s\n", *av);
			grim_it(*av);
			av++;
		}
	}
	else
	{
		if (!(input = ft_stdin()))
			return (1);
		printf("stdin grim it: %s", input); //TODO: remove
		grim_it(input);
	}
	return (0);
}
