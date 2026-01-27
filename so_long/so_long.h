/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:45:29 by montser           #+#    #+#             */
/*   Updated: 2026/01/27 15:08:03 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SIZE 64
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define QUIT_BUTTON 113

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_rows;
	int		map_cols;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		collectibles;
	int		exit_found;
	int		moves;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
}			t_game;

int			empty_get_next_line(int fd);
int			parse(char *input[]);
void		init_game_variables(t_game *game);
int			check_ber_extension(char *filename);
void		exit_with_error(int error_code);
void		free_map(char **map);
char		**read_map(int fd);
int			check_map(t_game *game);
int			open_file(char *filename);
void		start_game(t_game *game);
void		start_game(t_game *game);
void		*select_tile_image(t_game *game, char tile);
void		load_images(t_game *game);
void		render_map(t_game *game);
int			handle_keypress(int keycode, t_game *game);
int			close_game(t_game *game);
void		move(t_game *game, int px, int py);
char		**copy_map(char **original_map, int rows);
void		flood_fill(char **map, int x, int y, t_game *game);
void		count_char(char c, int *player, t_game *game);
void		set_position(t_game *game, int x, int y, char tile);
#endif