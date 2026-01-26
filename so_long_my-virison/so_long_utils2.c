/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: montser <montser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 01:50:03 by montser           #+#    #+#             */
/*   Updated: 2026/01/26 23:13:21 by montser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_variables(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->map_rows = 0;
	game->map_cols = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->collectibles = 0;
	game->exit_found = 0;
	game->moves = 0;
	game->img_wall = NULL;
	game->img_floor = NULL;
	game->img_player = NULL;
	game->img_exit = NULL;
	game->img_collectible = NULL;
}

void	*select_tile_image(t_game *game, char tile)
{
	if (tile == '1')
		return (game->img_wall);
	else if (tile == '0')
		return (game->img_floor);
	else if (tile == 'P')
		return (game->img_player);
	else if (tile == 'E')
		return (game->img_exit);
	else if (tile == 'C')
		return (game->img_collectible);
	return (NULL);
}

void	move(t_game *game, int px, int py)
{
	if (game->map[py][px] == '1')
		return ;
	if (game->map[py][px] == 'E' && game->collectibles > 0)
		return ;
	if (game->map[py][px] == 'C')
		game->collectibles--;
	if (game->map[py][px] == 'E' && game->collectibles == 0)
	{
		ft_printf("Checkmate! You've won the battle in %d moves.\n", game->moves
			+ 1);
		close_game(game);
	}
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = px;
	game->player_y = py;
	game->map[game->player_y][game->player_x] = 'P';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
}

char	*read_map_to_string(int fd, int *flag)
{
	char	*linear_map;
	char	*line;
	char	*temp;

	line = ft_strdup("");
	linear_map = ft_strdup("");
	*flag = 0;
	if (!line || !linear_map)
		return (NULL);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && ft_strncmp(line, "\n", 1) == 0)
			*flag = 1;
		temp = linear_map;
		linear_map = ft_strjoin(linear_map, line);
		free(temp);
		if (!linear_map)
			return (NULL);
	}
	free(line);
	return (linear_map);
}

char	**read_map(int fd)
{
	char	*linear_map;
	char	**map;
	int		flag;

	linear_map = read_map_to_string(fd, &flag);
	if (!linear_map)
		return (NULL);
	map = ft_split(linear_map, '\n');
	free(linear_map);
	if (flag)
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}
