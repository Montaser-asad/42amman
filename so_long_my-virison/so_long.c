/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: montser <montser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:28:18 by montser           #+#    #+#             */
/*   Updated: 2026/01/26 03:25:38 by montser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		exit(1);
	}
	if (parse(argv) == 1)
		exit(1);
	return (0);
}
