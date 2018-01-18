# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scamargo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 15:20:51 by scamargo          #+#    #+#              #
#    Updated: 2018/01/17 19:18:36 by scamargo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = grimly
FLAGS = -Werror -Wall -Wextra -L. -lft
SRCS = main.c validate_map.c

all:
	@gcc -o $(NAME) $(FLAGS) $(SRCS)

debug:
	@gcc -o $(NAME) $(FLAGS) $(SRCS)

fclean:
	@/bin/rm -f grimly

re: fclean all
