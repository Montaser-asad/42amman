/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: montser <montser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:46:31 by montser           #+#    #+#             */
/*   Updated: 2026/01/26 00:29:17 by montser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(int fd)
{
	char	*line;
	char	*map;
	char	*temp;

	line = get_next_line(fd);
	map = ft_strdup("");
	if (!line || !map)
		return (NULL);
	while (line)
	{
		temp = map;
		map = ft_strjoin(map, line);
		free(temp);
		free(line);
		if (!map)
			return (NULL);
		line = get_next_line(fd);
	}
	free(line);
	return (ft_split(map, '\n'));
}
