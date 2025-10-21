/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anashwan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:28:42 by anashwan          #+#    #+#             */
/*   Updated: 2025/02/22 20:57:35 by anashwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	read_file(char *str, char *num);

void	hundreds(char n, char *buffer_name)
{
	char	send[2];

	printf("\nHundreds\n");
	send [0] = n;
	send[1] = '\0';
	read_file(buffer_name, send);
	read_file(buffer_name, "100");
}

void	tens(char n, char *buffer_name)
{
	char	send[3];

	printf("\nTens\n");
	send[0] = n;
	send[1] = '0';
	send[2] = '\0';
	printf("\nCalling read_file from tens with send = %s...\n", send);
	read_file(buffer_name, send);
}

void	tash(char n, char m, char *buffer_name)
{
	char	send[3];

	printf("\nTash\n");
	send[0] = n;
	send[1] = m;
	send[2] = '\0';
	printf("\nCalling read_file from tash with send = %s...\n", send);
	read_file(buffer_name, send);
}

void	ones(char n, char *buffer_name)
{
	char	send[2];

	printf("\nOnes\n");
	send[0] = n;
	send[1] = '\0';
	printf("\nCalling read_file from ones with semd = %s...\n", send);
	read_file(buffer_name, send);
}
