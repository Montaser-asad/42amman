/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:42:36 by masad             #+#    #+#             */
/*   Updated: 2026/01/22 16:53:36 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 199309L
#include "libft/libft.h"
#include <signal.h>

static char	*g_message = NULL;

void	cnct(char c)
{
	char	tmp[2];
	char	*joined;

	if (g_message == NULL)
		g_message = ft_strdup("");
	tmp[0] = c;
	tmp[1] = '\0';
	joined = ft_strjoin(g_message, tmp);
	free(g_message);
	g_message = joined;
}

void	sighandler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				i;
	int						pid;

	pid = info->si_pid;
	(void)context;
	c <<= 1;
	if (sig == SIGUSR1)
		c |= 1;
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			cnct('\n');
			ft_printf("%s", g_message);
			free(g_message);
			g_message = NULL;
		}
		else
			cnct(c);
		i = 0;
		c = 0;
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
