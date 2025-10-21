/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:54:13 by masad             #+#    #+#             */
/*   Updated: 2025/02/25 20:33:17 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	prntargalph(char **ar, int size)
{
	char	*x;
	int		a;
	int		b;
	int		i;

	a = 0;
	while (a++ < size - 1)
	{
		b = a + 1;
		while (b < size)
		{
			i = -1;
			if (ft_strcmp(ar[a], ar[b]) > 0)
			{
				x = ar[a];
				ar[a] = ar[b];
				ar[b] = x;
			}
			b++;
		}
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	prntargalph(argv, argc);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
