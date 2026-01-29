/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 02:19:47 by montser           #+#    #+#             */
/*   Updated: 2026/01/29 21:11:30 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_game *game)
{
	int		w;
	int		h;
	void	*(*ftoimg)(void *, char *, int *, int *);

	ftoimg = mlx_xpm_file_to_image;
	game->img_playerR = ftoimg(game->mlx, "./imgs/Player_R.xpm", &w, &h);
	game->img_playerL = ftoimg(game->mlx, "./imgs/Player_L.xpm", &w, &h);
	game->img_player = ftoimg(game->mlx, "./imgs/Player.xpm", &w, &h);
	game->img_exit = ftoimg(game->mlx, "./imgs/Exit.xpm", &w, &h);
	game->img_exitC = ftoimg(game->mlx, "./imgs/Exit_C.xpm", &w, &h);
	game->img_collectible = ftoimg(game->mlx, "./imgs/Collectible.xpm", &w, &h);
	game->img_floor = ftoimg(game->mlx, "./imgs/Tiles.xpm", &w, &h);
	game->img_wall = ftoimg(game->mlx, "./imgs/Wall.xpm", &w, &h);
	if (!game->img_player || !game->img_exit || !game->img_collectible
		|| !game->img_floor || !game->img_wall || !game->img_playerR
		|| !game->img_playerL || !game->img_exitC)
		exit_with_error(4, game);
}

void	render_map(t_game *game)
{
	int		i;
	int		j;
	void	*img;
	char	tile;
	int		(*putimg)(void *, void *, void *, int, int);

	putimg = mlx_put_image_to_window;
	i = 0;
	while (i < game->map_rows)
	{
		j = 0;
		while (j < game->map_cols)
		{
			tile = game->map[i][j];
			img = select_tile_image(game, tile);
			if (img)
				putimg(game->mlx, game->win, img, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	print_moves_to_window(t_game *game)
{
	char	*moves_str;
	char	*display;

	moves_str = ft_itoa(game->moves);
	if (moves_str)
	{
		display = ft_strjoin("Moves: ", moves_str);
		if (!display)
			exit_with_error(0, game);
		if (display)
		{
			mlx_string_put(game->mlx, game->win, 26, 44, 0xff0000, display);
			free(display);
		}
		free(moves_str);
	}
}

int	handle_keypress(int keycode, t_game *game)
{
	(void)game;
	if (keycode == KEY_W || keycode == KEY_UP)
		move(game, game->player_x, game->player_y - 1);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->direction = 'L';
		move(game, game->player_x - 1, game->player_y);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->direction = 'R';
		move(game, game->player_x + 1, game->player_y);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move(game, game->player_x, game->player_y + 1);
	else if (keycode == KEY_ESC || keycode == QUIT_BUTTON)
		close_game(game);
	return (0);
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_with_error(0, game);
	load_images(game);
	if (!game->img_playerR || !game->img_playerL || !game->img_exit
		|| !game->img_collectible || !game->img_floor || !game->img_wall)
		exit_with_error(4, game);
	game->win = mlx_new_window(game->mlx, game->map_cols * TILE_SIZE,
			game->map_rows * TILE_SIZE, "so_long");
	if (!game->win)
	{
		free_map(game->map);
		exit_with_error(0, game);
	}
	render_map(game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
}
