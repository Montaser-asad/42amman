/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: montser <montser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 20:55:35 by masad             #+#    #+#             */
/*   Updated: 2026/01/25 18:03:38 by montser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*free_and_null(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*extract_line(char *stach)
{
	int		i;
	char	*rv;

	i = 0;
	while (stach[i] && stach[i] != '\n')
		i++;
	rv = ft_substr(stach, 0, i + (stach[i] == '\n'));
	return (rv);
}

char	*update_stach(char *stach)
{
	int		s;
	int		e;
	char	*df;

	s = 0;
	while (stach[s] && stach[s] != '\n')
		s++;
	if (!stach[s])
		return (free_and_null(&stach));
	e = ft_strlen(stach) - s;
	df = ft_substr(stach, s + 1, e);
	free(stach);
	return (df);
}

char	*handel_stach(int fd, char *stach)
{
	char	*buffer;
	int		br;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	br = 1;
	while (br > 0 && !ft_strchr(stach, '\n'))
	{
		br = read(fd, buffer, BUFFER_SIZE);
		if (br < 0)
			if (!free_and_null(&buffer))
				return (free_and_null(&stach));
		buffer[br] = '\0';
		stach = ft_strjoin(stach, buffer);
		if (!stach)
			return (free_and_null(&buffer));
	}
	free(buffer);
	return (stach);
}

char	*get_next_line(int fd)
{
	static char	*stach[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stach[fd] = handel_stach(fd, stach[fd]);
	if (!stach[fd] || !*stach[fd])
		return (free_and_null(&stach[fd]));
	line = extract_line(stach[fd]);
	if (!line)
		return (free_and_null(&stach[fd]));
	stach[fd] = update_stach(stach[fd]);
	if (stach[fd] && *stach[fd] == '\0')
		free_and_null(&stach[fd]);
	return (line);
}
