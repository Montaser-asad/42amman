/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: montser <montser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 20:37:07 by montser           #+#    #+#             */
/*   Updated: 2026/01/25 18:06:16 by montser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strncmp(&filename[len - 4], ".ber", 4) != 0)
		return (0);
	return (1);
}

int	parse(char *input[])
{
	if (check_ber_extension(input[1]) == 0)
	{
		ft_printf("Error\nInvalid file extension\n");
		return (1);
	}
	if (check_map(input[1]) != 0)
	{
		ft_printf("Error\nInvalid map\n");
		return (1);
	}
	return (0);
}
