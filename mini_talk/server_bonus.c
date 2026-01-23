/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: montser <montser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:42:36 by masad             #+#    #+#             */
/*   Updated: 2026/01/24 02:44:35 by montser          ###   ########.fr       */
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

void	concat(char charecter)
{
	char	tmp[2];
	char	*joined;

	if (g_message == NULL)
		g_message = ft_strdup("");
	tmp[0] = charecter;
	tmp[1] = '\0';
	joined = ft_strjoin(g_message, tmp);
	free(g_message);
	g_message = joined;
}

void	sighandler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	charecter;
	static int				idex;
	int						pid;

	(void)context;
	charecter <<= 1;
	pid = info->si_pid;
	if (sig == SIGUSR1)
		charecter |= 1;
	idex++;
	if (idex == 8)
	{
		if (charecter == '\0')
		{
			concat('\n');
			ft_printf("%s", g_message);
			free_message();
			kill(pid, SIGUSR2);
		}
		else
			concat(charecter);
		idex = 0;
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
