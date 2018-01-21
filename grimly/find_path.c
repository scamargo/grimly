/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:43:43 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/20 18:47:52 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "grimly.h"

#define BOTTOM_PARENT 0x01
#define RIGHT_PARENT 0x02
#define TOP_PARENT 0x03
#define LEFT_PARENT 0x04
#define EXIT 0x08
#define GET_PARENT(c) (c & 0x07)

static void	find_children(char *map, int i, t_grim *card, t_list *queue)
{
	char empty;
	char exit;
	int	 columns;
	int		lines;
	int		child_i;

	empty = card->empty;
	exit = card->exit;
	columns = card->columns;
	lines = card->lines;
	child_i = i - columns - 1;
	if (i > columns && (map[child_i] == empty || map[child_i] == exit))
	{
		if (map[child_i] == exit)
			map[child_i] = 0 | EXIT;
		map[child_i] = map[child_i] | BOTTOM_PARENT;
		ft_lstaddtoend(&queue, ft_lstnew(&child_i, sizeof(int)));
	}
	child_i = i - 1;
	if (i > 0 && (map[child_i] == empty || map[child_i] == exit))
	{
		if (map[child_i] == exit)
			map[child_i] = 0 | EXIT;
		map[child_i] = map[child_i] | RIGHT_PARENT;
		ft_lstaddtoend(&queue, ft_lstnew(&child_i, sizeof(int)));
	}
	child_i = i + 1;
	if (i < (columns + 1) * lines && (map[child_i] == empty || map[child_i] == exit))
	{
		if (map[child_i] == exit)
			map[child_i] = 0 | EXIT;
		map[child_i] = map[child_i] | LEFT_PARENT;
		ft_lstaddtoend(&queue, ft_lstnew(&child_i, sizeof(int)));
	}
	child_i = i + columns + 1;
	if (i < ((columns + 1) * (lines - 1)) && (map[child_i] == empty || map[child_i] == exit))
	{
		if (map[child_i] == exit)
			map[child_i] = 0 | EXIT;
		map[child_i] = map[child_i] | TOP_PARENT;
		ft_lstaddtoend(&queue, ft_lstnew(&child_i, sizeof(int)));
	}
}

int		find_path(t_grim *card)
{
	t_list *queue; // arraylist may be better
	char	*map;
	int		i;
	int		steps;
	i = card->entrance_pos;
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
	while (map[i] != card->entrance)
	{
		if (!(map[i] & EXIT))
		{
			steps++;
			card->map[i] = card->path;
		}
		if (GET_PARENT(map[i]) == BOTTOM_PARENT)
			i += card->columns + 1;
		else if (GET_PARENT(map[i]) == RIGHT_PARENT)
			i += 1;
		else if (GET_PARENT(map[i]) == TOP_PARENT)
			i -= (card->columns + 1);
		else if (GET_PARENT(map[i]) == LEFT_PARENT)
			i -= 1;
	}
	ft_putstr(card->card);
	return (steps);
}
