/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:37:07 by montser           #+#    #+#             */
/*   Updated: 2026/01/27 14:54:51 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse(char *input[])
{
	int		fd;
	t_game	game;

	fd = open_file(input[1]);
	init_game_variables(&game);
	game.map = read_map(fd);
	if (!game.map)
		exit_with_error(3);
	if (check_map(&game) != 0)
	{
		free_map(game.map);
		exit_with_error(3);
	}
	start_game(&game);
	return (0);
}
