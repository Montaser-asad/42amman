/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:46:31 by montser           #+#    #+#             */
/*   Updated: 2026/01/29 15:50:42 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_with_error(int error_code, t_game *game)
{
	char	*message[5];

	message[0] = "Malloc failed";
	message[1] = "Invalid file extension";
	message[2] = "Could not open file";
	message[3] = "Invalid map";
	message[4] = "Failed to load images";
	if (game)
		close_game(game);
	ft_printf("Error\n%s\n", message[error_code]);
	exit(1);
}

int	check_ber_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (1);
	if (ft_strncmp(&filename[len - 4], ".ber", 4) != 0)
		return (1);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	open_file(char *filename)
{
	int	fd;

	if (check_ber_extension(filename))
		exit_with_error(1, NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_with_error(2, NULL);
	return (fd);
}

void	count_char(char c, int *player, t_game *game)
{
	if (c == 'P')
		(*player)++;
	else if (c == 'E')
		game->exit_found++;
	else if (c == 'C')
		game->collectibles++;
}
