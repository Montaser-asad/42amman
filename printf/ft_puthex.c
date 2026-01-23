/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: montser <montser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:44:23 by masad             #+#    #+#             */
/*   Updated: 2026/01/23 04:05:52 by montser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puthex(unsigned int nb, char hex, int *cnt)
{
	char	x;

	(*cnt)++;
	if (nb >= 16)
		ft_puthex(nb / 16, hex, cnt);
	x = (nb % 16);
	if (x <= 9)
		x = (nb % 16) + '0';
	else
		x += (hex - 10);
	write(1, &x, 1);
}
