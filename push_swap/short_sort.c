/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:22:01 by masad             #+#    #+#             */
/*   Updated: 2026/01/15 17:37:21 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_list **a)
{
	int	f;
	int	b;
	int	l;

	f = (*a)->content;
	b = (*a)->next->content;
	l = ft_lstlast(*a)->content;
	if (f > b && b < l && f < l)
		sa(a);
	else if (f > b && b > l)
	{
		sa(a);
		rra(a);
	}
	else if (f > b && b < l && f > l)
		ra(a);
	else if (f < b && b > l && f < l)
	{
		sa(a);
		ra(a);
	}
	else if (f < b && b > l && f > l)
		rra(a);
}

static void	sort4_5_helper(t_list **a, t_list **b, int size)
{
	put_min_top(a);
	if (is_sorted(*a))
	{
		if (size == 5)
			pa(a, b);
		return ;
	}
	pb(b, a);
	sort3(a);
	pa(a, b);
	if (size == 5)
		pa(a, b);
}

void	short_sort(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 1 || is_sorted(*a))
		return ;
	if (size == 2)
	{
		if ((*a)->content > ((*a)->next)->content)
			sa(a);
		return ;
	}
	if (size == 3)
	{
		sort3(a);
		return ;
	}
	if (size == 5)
	{
		put_min_top(a);
		if (is_sorted(*a))
			return ;
		pb(b, a);
	}
	sort4_5_helper(a, b, size);
}
