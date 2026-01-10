/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:22:01 by masad             #+#    #+#             */
/*   Updated: 2026/01/06 20:04:28 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list *a)
{
	int	min;
	int	idx;
	int	i;

	min = a->content;
	idx = 1;
	i = 1;
	while (a)
	{
		if (a->content < min)
		{
			min = a->content;
			idx = i;
		}
		a = a->next;
		i++;
	}
	return (idx);
}
void	put_min_top(t_list **a)
{
	int	size;
	int	p;

	size = ft_lstsize((*a));
	p = find_min(*a);
	if (p == 1)
		return ;
	else if (p == 2)
		sa(a);
	else if (p == 3)
	{
		ra(a);
		ra(a);
	}
	else if (p == 4 && size == 4)
		rra(a);
	else if (p == 4 && size == 5)
	{
		rra(a);
		rra(a);
	}
	else if (p == 5 && size == 5)
		rra(a);
}
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
void	sort5_4(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 4)
	{
		put_min_top(a);
		pb(b, a);
		sort3(a);
		pa(a, b);
	}
	else if (ft_lstsize(*a) == 5)
	{
		put_min_top(a);
		pb(b, a);
		put_min_top(a);
		pb(b, a);
		sort3(a);
		sb(b);
		pa(a, b);
		pa(a, b);
	}
}

void	short_sort(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 1)
		return ;
	if (size == 2)
		if ((*a)->content > ((*a)->next)->content)
			sa(a);
	if (size == 3)
		sort3(a);
	if (size == 4 || size == 5)
	{
		if (size == 5)
		{
			put_min_top(a);
			pb(b, a);
		}
		put_min_top(a);
		pb(b, a);
		sort3(a);
		pa(a, b);
		if (size == 5)
			pa(a, b);
	}
}
