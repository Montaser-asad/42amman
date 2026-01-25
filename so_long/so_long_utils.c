/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: montser <montser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:46:31 by montser           #+#    #+#             */
/*   Updated: 2026/01/25 22:46:11 by montser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(int fd)
{
	char	*temp;
	char	*map;

	temp = get_next_line(fd);
	map = ft_strdup("");
	if (!temp)
		return (NULL);
	while (map)
	{
		map = ft_strjoin(map, temp);
		if (!map)
			return (NULL);
		temp = get_next_line(fd);
	}
	return (ft_split(map, '\n'));
}
