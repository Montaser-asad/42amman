/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:42:36 by masad             #+#    #+#             */
/*   Updated: 2026/01/27 16:10:25 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 199309L
#include "libft/libft.h"
#include <signal.h>

static char	*g_message = NULL;

void	free_message(void)
{
	if (g_message)
	{
		free(g_message);
		g_message = NULL;
	}
}

void	cnct(char charecter)
{
	char	tmp[2];
	char	*joined;

	if (g_message == NULL)
	{
		g_message = ft_strdup("");
		if (!g_message)
		{
			ft_printf("Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
	}
	tmp[0] = charecter;
	tmp[1] = '\0';
	joined = NULL; // ft_strjoin(g_message, tmp);
	free(g_message);
	if (!joined)
	{
		ft_printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	g_message = joined;
}

void	sighandler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	charecter;
	static int				index;
	int						pid;

	pid = info->si_pid;
	(void)context;
	charecter <<= 1;
	if (sig == SIGUSR1)
		charecter |= 1;
	index++;
	if (index == 8)
	{
		if (charecter == '\0')
		{
			cnct('\n');
			ft_printf("%s", g_message);
			free_message();
		}
		else
			cnct(charecter);
		index = 0;
		charecter = 0;
	}
	kill(pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("Server PID: %d\n", getpid());
	action.sa_sigaction = &sighandler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
