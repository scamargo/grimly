/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 15:30:32 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/17 16:31:08 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	char *input;
	// read arguments, else read from stdin
	if (ac > 1)
	{
		while (*(++av))
		{
			printf("av grim it: %s\n", *av);
			//grim_it(*av);
			//(*av)++;
		}
	}
	else
	{
		if (!(input = ft_stdin()))
			return (1);
		printf("stdin grim it: %s", input); //TODO: remove
		//grim_it(input);
	}
	return (0);
}
