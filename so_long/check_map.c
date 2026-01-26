/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 21:45:29 by montser           #+#    #+#             */
/*   Updated: 2026/01/26 19:34:56 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(t_game *game)
{
	int		i;
	size_t	row;

	row = ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != row)
			return (1);
		i++;
	}
	game->map_rows = i;
	game->map_cols = (int)row;
	return (0);
}

int	check_borders(t_game *game)
{
	char	**map;
	int		i;
	int		rows;
	int		cols;

	map = game->map;
	rows = 0;
	while (map[rows])
		rows++;
	cols = ft_strlen(map[0]);
	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}
int	check_path(t_game *game)
{
	int		holder;
	char	**map_copy;

	map_copy = copy_map(game->map, game->map_rows);
	game->exit_found = 0;
	holder = game->collectibles;
	flood_fill(map_copy, game->player_x, game->player_y, game);
	free_map(map_copy);
	if (game->collectibles != 0 || game->exit_found != 1)
		return (1);
	game->collectibles = holder;
	return (0);
}

int	check_characters(t_game *game)
{
	int		player_count;
	char	c;
	int		i;
	int		j;

	player_count = 0;
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			c = game->map[i][j];
			if (c != 'P' && c != 'E' && c != 'C' && c != '0' && c != '1')
				return (1);
			count_char(c, &player_count, game);
			if (c == 'P')
				game->player_x = j;
			if (c == 'P')
				game->player_y = i;
		}
	}
	if (player_count != 1 || game->exit_found != 1 || game->collectibles < 1)
		return (1);
	return (0);
}

int	check_map(t_game *game)
{
	if (check_rectangular(game))
		return (1);
	if (check_borders(game))
		return (1);
	if (check_characters(game))
		return (1);
	if (check_path(game))
		return (1);
	return (0);
}
