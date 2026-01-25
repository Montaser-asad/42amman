/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:01:06 by masad             #+#    #+#             */
/*   Updated: 2025/02/10 15:09:20 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	p;
	int	c;
	int	s;

	s = size;
	c = 0;
	p = 0;
	while (c < s)
	{
		while (p < s)
		{
			if (tab[p] > tab[c])
			{
				tab[p] = tab[p] + tab[c];
				tab[c] = tab[p] - tab[c];
				tab[p] = tab[p] - tab[c];
			}
			p++;
		}
		p = 0;
		c++;
	}
}
