/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: montser <montser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 02:19:47 by montser           #+#    #+#             */
/*   Updated: 2026/01/26 03:23:38 by montser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        exit_with_error(0);
    game->win = mlx_new_window(game->mlx, game->map_cols * TILE_SIZE,
            game->map_rows * TILE_SIZE, "so_long");
    if (!game->win)
    {
        free_map(game->map);
        exit_with_error(0);
    }
    
    mlx_loop(game->mlx);
}