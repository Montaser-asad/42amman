/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 20:29:58 by masad             #+#    #+#             */
/*   Updated: 2026/01/15 20:31:03 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	handle_input(char const **argv, char **split)
{
	if (!parse(argv) || parse(argv) == 2)
	{
		if (parse(argv) == 2)
		{
			if (split)
				free_split(split);
			return (0);
		}
		push_swap(argv);
	}
	else
	{
		if (split)
			free_split(split);
		write(2, "Error\n", 6);
		return (1);
	}
	if (split)
		free_split(split);
	return (0);
}
