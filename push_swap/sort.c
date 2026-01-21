/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:26:01 by masad             #+#    #+#             */
/*   Updated: 2026/01/19 20:06:58 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **a, t_list **b)
{
	sort_i(a);
	radix(a, b);
}

int	longest_len(t_list *a)
{
	int	max_index;
	int	bits;

	max_index = 0;
	bits = 0;
	while (a)
	{
		if (a->index > max_index)
			max_index = a->index;
		a = a->next;
	}
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void	radix(t_list **a, t_list **b)
{
	int	i;
	int	j;
	int	l;
	int	n;

	i = 0;
	l = ft_lstsize(*a);
	n = longest_len(*a);
	while (i < n)
	{
		j = 0;
		while (j < l)
		{
			if (((((*a)->index) >> i) & 1) == 0)
				pb(b, a);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
