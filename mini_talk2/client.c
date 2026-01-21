/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:26:33 by masad             #+#    #+#             */
/*   Updated: 2026/01/21 20:33:32 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 500
#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>

int		g_ack_received;

void	ack(int sig)
{
	(void)sig;
	g_ack_received = 1;
}

void	send_sig(int pid, const char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_ack_received = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_ack_received == 0);
		i--;
	}
}

int	check_pid(int pid)
{
	if (pid <= 0)
		return (-1);
	if (kill(pid, 0) == -1)
		return (-1);
	if (pid > 4194304)
		return (-1);
	return (0);
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
	if (check_pid(pid) == -1)
	{
		ft_printf("Error: Invalid PID\n");
		exit(0);
	}
	signal(SIGUSR1, ack);
	message = argv[2];
	while (message[++i])
		send_sig(pid, message[i]);
	send_sig(pid, '\0');
	return (0);
}
