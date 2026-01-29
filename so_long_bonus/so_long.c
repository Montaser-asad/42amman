/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:28:18 by montser           #+#    #+#             */
/*   Updated: 2026/01/29 18:45:32 by masad            ###   ########.fr       */
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
		exit_with_error(3, NULL);
	if (check_map(&game) != 0)
	{
		free_map(game.map);
		exit_with_error(3, NULL);
	}
	start_game(&game);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		exit(1);
	}
	if (parse(argv) == 1)
		exit(1);
	return (0);
}
