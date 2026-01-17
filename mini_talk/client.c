/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:26:33 by masad             #+#    #+#             */
/*   Updated: 2026/01/17 19:14:00 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 500
#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>

void	send_sig(int pid, const char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(420);
		i--;
	}
}

int	main(int argc, const char *argv[])
{
	int			pid;
	const char	*message;
	int			i;

	i = -1;
	if (argc != 3)
	{
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	while (message[++i])
		send_sig(pid, message[i]);
	send_sig(pid, '\0');
	return (0);
}
