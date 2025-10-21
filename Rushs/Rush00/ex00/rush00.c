/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaatreh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:44:21 by rzaatreh          #+#    #+#             */
/*   Updated: 2025/02/08 16:23:20 by rzaatreh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	j;
	int	i;

	i = 1;
	if (x <= 0 || y <= 0)
		return ;
	while (i <= y)
	{
		j = 1;
		while (j <= x)
		{
			if ((j > 1 && j < x) && (i > 1 && i < y))
				ft_putchar(' ');
			else if ((j > 1 && j < x) && (i == 1 || i == y))
				ft_putchar('-');
			else if ((j == 1 || j == x) && (i > 1 && i < y))
				ft_putchar('|');
			else
				ft_putchar('o');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
