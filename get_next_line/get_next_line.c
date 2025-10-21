/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_ine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:58:20 by masad             #+#    #+#             */
/*   Updated: 2025/09/29 14:14:05 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	
	char			*buffer;
	ssize_t			bytesRead;
	static t_list	*node;
	t_list			*tmp;
	char			*line;
	int				cnt;
	char			*tmper;
	// size_t			size;
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytesRead = read(fd, buffer, BUFFER_SIZE);
	tmp = node;
	cnt = 0;
	line = NULL;
	while (bytesRead > 0 && !ft_strchr(buffer, '\n'))
	{
		tmp->content = buffer;
		// printf ("%s" , tmp->content);
		ft_lstadd_back(&node, tmp);
		free(tmp);
		bytesRead = read(fd, buffer, BUFFER_SIZE);
	}
	tmper = line ;
	while (node)
	{
		line = node->content;
		line += BUFFER_SIZE;
		node = node->next;
	}
	// while (bytesRead > 0)
	// {
	// 	bytesRead = read(fd, buffer, BUFFER_SIZE);
	// 	size = ft_strlen(buffer);
	// 	printf ("%zd" , bytesRead);
	// 	tmp->content = buffer;
	// 	ft_lstadd_back(&node, tmp);
	// 	if (ft_strchr(buffer, '\n'))
	// 	{
	// 		while (node)
	// 		{
	// 			line = malloc((BUFFER_SIZE)*cnt + 1);
	// 			if (!line)
	// 				return (NULL);
	// 			*line++ = *node->content++;
	// 			node = node->next;
	// 		}
	// 		*line = '\0';
	// 		return (line);
	// 	}
	// 	cnt++;
	// }
	return (tmper);
}

int	main(void)
{
	int		fd;
	char	*line;
	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	return (0);
}
