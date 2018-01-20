/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:43:43 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/19 16:42:16 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "grimly.h"

#define BOTTOM_PARENT 0x01
#define EXIT 0x04

static void	find_children(char *map, int i, t_grim *card, t_list *queue)
{
	char empty;
	char exit;
	int	 columns;
	int		child_i;

	empty = card->empty;
	exit = card->exit;
	columns = card->columns;
	// look up
	//ft_putendl("ADDING CHILD: ");
	child_i = i - columns - 1;
	if (i > columns && (map[child_i] == empty || map[child_i] == exit))
	{
		if (map[child_i] == exit)
			map[child_i] = 0 | EXIT;
		map[child_i] = map[child_i] | BOTTOM_PARENT;
		ft_lstaddtoend(&queue, ft_lstnew(&child_i, sizeof(int)));
		//ft_putendl("SUCCESS");
	}
	// look right
	// look down
	// look left
}

int		find_path(t_grim *card)
{
	t_list *queue; // arraylist may be better
	char	*map;
	int		i;
	int		steps;
	i = card->entrance_pos;// TODO: fix this!
	queue = ft_lstnew(&i, sizeof(int));
	map = ft_strdup(card->map);
	while (!(map[i] & EXIT))
	{
		find_children(map, i, card, queue);
		if (!queue->next)
			return (0);
		queue = queue->next;
		i = *(int*)queue->content;
	}
	steps = 0;
	// TODO: don't write over exit
	while (map[i] != card->entrance)
	{
		if (!(map[i] & EXIT))
		{
			steps++;
			card->map[i] = card->path;
		}
		if (map[i] & BOTTOM_PARENT)
			i += card->columns + 1;
	}
	ft_putstr(card->card);
	return (steps);
}
