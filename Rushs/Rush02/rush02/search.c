/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:28:31 by masad             #+#    #+#             */
/*   Updated: 2025/02/22 21:28:33 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	print_number(char *buffer, int i)
{
	while (buffer[i] && buffer[i] != '\n')
	{
		write(1, &buffer[i], 1);
		i++;
	}
}

void	direct_numbers(char *buffer, char *num)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (num[len])
		len++;
	while (buffer[i])
	{
		j = 0;
		while (num[j] == buffer[i + j])
			j++;
		if (j == len && ((buffer[i + j] <= 13 && buffer[i + j] >= 9)
				|| buffer[i + j] == ':'))
		{
			i = i + j;
			while ((buffer[i] <= 13 && buffer[i] >= 9)
				|| buffer[i] == 32 || buffer[i] == ':')
				i++;
			print_number(buffer, i);
			break ;
		}
		i++;
	}
}

void	read_file(char *str, char *num)
{
	int		dictionary;
	int		counter;
	char	temp_buff[1];
	char	*buffer;

	counter = 0;
	dictionary = open(str, O_RDONLY);
	if (dictionary < 0)
		write(1, "Dict Error\n", 12);
	while (read(dictionary, temp_buff, 1) > 0)
		counter++;
	close(dictionary);
	dictionary = open(str, O_RDONLY);
	buffer = malloc(counter);
	read(dictionary, buffer, counter);
	direct_numbers(buffer, num);
	close(dictionary);
	free(buffer);
}
