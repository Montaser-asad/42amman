/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 11:16:11 by masad             #+#    #+#             */
/*   Updated: 2025/11/09 20:25:33 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *stach)
{
	int	i;
	char *rv;
	
	i = 0;
	while (stach[i] != '\0' )
		{
			if (stach[i] == '\n')
				break;
			i++;
		}
	rv = ft_substr(stach, 0, i + 1);
	return (rv);
}

char	*update_stach(char *stach)
{
	int s;
	int e;
	char *rv;

	e = ft_strlen(stach);
	s = 0;
	while (stach[s] != '\0' )
		{
			if (stach[s] == '\n')
				break;
			s++;
		}
	e -= s;
	rv = ft_substr(stach, s + 1, e);
	free(stach);
	return (rv);
}
char	*get_next_line(int fd)
{
	static char	*stach;
	char		*buffer;
	char		*tmp;
	char		*line;
	int			br;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	br = 1;
	while (br > 0 && !ft_strchr(stach, '\n'))
	{
		br = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		tmp = ft_strjoin(stach, buffer);
		if (!tmp)
		{
			free(buffer);
			return (NULL);
		}
		free(stach);
		stach = tmp;
	}
	free(buffer);
	if (br < 0)
	{
		free(stach);
		return (NULL);
	}
	line = extract_line(stach);
	if (!line)
	{
		free(stach);
		return (NULL);
	}
	stach = update_stach(stach);
	return (line);
}

int	main(void)
{
	int fd;
	char *line;

	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	while(*line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}