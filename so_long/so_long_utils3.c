/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:33:56 by masad             #+#    #+#             */
/*   Updated: 2026/01/26 19:58:33 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **original_map, int rows)
{
	char	**new_map;
	int		i;

	new_map = (char **)malloc((rows + 1) * sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		new_map[i] = ft_strdup(original_map[i]);
		if (!new_map[i])
		{
			free_map(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[rows] = NULL;
	return (new_map);
}

void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		game->collectibles--;
	if (map[y][x] == 'E')
		game->exit_found++;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x, y - 1, game);
	return ;
}

int	close_game(t_game *game)
{
	free_map(game->map);
	if (game->mlx)
	{
		mlx_destroy_image(game->mlx, game->img_wall);
		mlx_destroy_image(game->mlx, game->img_floor);
		mlx_destroy_image(game->mlx, game->img_player);
		mlx_destroy_image(game->mlx, game->img_exit);
		mlx_destroy_image(game->mlx, game->img_collectible);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
}
