/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: montser <montser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 21:45:29 by montser           #+#    #+#             */
/*   Updated: 2026/01/25 22:46:27 by montser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(char **map)
{
	int		i;
	size_t	row_length;

	row_length = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != row_length)
			return (0);
		i++;
	}
	return (1);
}

int	check_borders(char **map)
{
	int	i;
	int	rows;
	int	cols;

	rows = 0;
	while (map[rows])
		rows++;
	cols = ft_strlen(map[0]);
	i = 0;
	while (i < cols)
	{
		if (map[0][i] != '1' || map[rows - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < rows)
	{
		if (map[i][0] != '1' || map[i][cols - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static void	count_char(char c, int *player, int *exit, int *collect)
{
	if (c == 'P')
		(*player)++;
	else if (c == 'E')
		(*exit)++;
	else if (c == 'C')
		(*collect)++;
}

int	check_charecters(char **map)
{
	int		counts[3];
	char	c;
	int		i;
	int		j;

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			c = map[i][j];
			if (c != 'P' && c != 'E' && c != 'C' && c != '0' && c != '1')
				return (1);
			count_char(c, &counts[0], &counts[1], &counts[2]);
		}
	}
	if (counts[0] != 1 || counts[1] < 1 || counts[2] < 1)
		return (1);
	return (0);
}

int	check_map(char *filename)
{
	char	**map;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	map = read_map(fd);
	if (!check_rectangular(map))
		return (1);
	if (!check_borders(map))
		return (1);
	if (check_charecters(map))
		return (1);
	return (0);
}
