/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: montser <montser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 18:45:29 by montser           #+#    #+#             */
/*   Updated: 2026/01/26 03:24:59 by montser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SIZE 64

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
	int		collectibles;
	int		moves;
	int		exit_found;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
}			t_game;

void		init_game_variables(t_game *game);
int			check_ber_extension(char *filename);
void		exit_with_error(int error_code);
void		free_map(char **map);
int			parse(char *input[]);
char		**read_map(int fd);
int			check_map(t_game *game);
int			open_file(char *filename);
void		start_game(t_game *game);
void		start_game(t_game *game);
#endif