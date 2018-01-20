/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grimly.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scamargo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 17:31:50 by scamargo          #+#    #+#             */
/*   Updated: 2018/01/19 16:05:13 by scamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRIMLY_H
# define GRIMLY_H

typedef struct	s_grim
{
	int		lines;
	int		columns;
	char	entrance;
	char	exit;
	char	path;
	char	empty;
	char	full;
	int		entrance_pos;
	char	*map;
	char	*card;
	//t_list	*exit_pos maybe I don't need this
}				t_grim;

int				card_is_valid(char *input_file, t_grim *card);
int				map_is_valid(char *input, t_grim *card);
void			find_path(t_grim *card);

#endif
