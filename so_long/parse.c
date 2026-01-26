/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: montser <montser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:37:07 by montser           #+#    #+#             */
/*   Updated: 2026/01/26 03:25:43 by montser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse(char *input[])
{
	int		fd;
	t_game	game;

	fd = open_file(input[1]);
	game.map = read_map(fd);
	init_game_variables(&game);
	if (!game.map)
		exit_with_error(0);
	if (check_map(&game) != 0)
	{
		free_map(game.map);
		exit_with_error(2);
	}
	start_game(&game);
	return (0);
}
