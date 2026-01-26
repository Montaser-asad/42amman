/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: montser <montser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:46:31 by montser           #+#    #+#             */
/*   Updated: 2026/01/26 02:09:43 by montser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_with_error(int error_code)
{
	char	*message[4];

	message[0] = "Malloc failed";
	message[1] = "Invalid file extension";
	message[2] = "Could not open file";
	message[3] = "Invalid map";
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
		exit_with_error(1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_with_error(2);
	return (fd);
}

char	**read_map(int fd)
{
	char	*linear_map;
	char	*line;
	char	**map;
	char	*temp;

	line = ft_strdup("");
	linear_map = ft_strdup("");
	if (!line || !linear_map)
		return (NULL);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && ft_strncmp(line, "\n", 1) == 0)
			exit_with_error(2);
		temp = linear_map;
		linear_map = ft_strjoin(linear_map, line);
		free(temp);
		if (!linear_map)
			return (NULL);
	}
	free(line);
	map = ft_split(linear_map, '\n');
	free(linear_map);
	return (map);
}
