/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:22:01 by masad             #+#    #+#             */
/*   Updated: 2026/01/04 21:26:06 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_list **a)
{
	if (((*a)->next)->content < (*a)->content) //(max > mid > min)
		if (((*a)->next)->content > ft_lstlast(a))
		{
			ra(a);
			sa(a);
		}
	if (ft_lstlast(a) > (*a)->content) //(min > max > mid)
		if (ft_lstlast(a) < ((*a)->next)->content)
		{
			rra(a);
			sa(a);
		}
	if (ft_lstlast(a) < (*a)->content) //(max > min > mid)
		if (ft_lstlast(a) > ((*a)->next)->content)
		{
			ra(a);
			sa(a);
		}
	if ((*a)->content > ft_lstlast(a)) //(mid > max > min)
		if ((*a)->content < ((*a)->next)->content)
			rra(a);
	if ((*a)->content < ft_lstlast(a)) //(mid > min > max)
		if ((*a)->content > ((*a)->next)->content)
			ra(a);
}
void	sort5(t_list **a, t_list **b)
{
	if ((*a)->content > (*b)->content)
		pb(b, a);
	else if ((*a)->content < (*b)->content)
	{
		pb(b, a);
		ra(a);
		pa(a, b);
		pa(a, b);
		sa(a);
		rrb(b);
	}
}
void	put_min_top(t_list **a)
{
	t_list	*t;

	t = *a;
}

void	short_sort(t_list **a, t_list **b)
{
	t_list	*t;

	t = NULL;
	if (ft_lstsize(*a) == 1)
		return ;
	else if (ft_lstsize(*a) == 2)
	{
		if ((*a)->content > ((*a)->next)->content)
			sa(a);
	}
	else if (ft_lstsize(*a) == 3)
		sort3(a);
	else if (ft_lstsize(*a) == 4)
		sort4(a, b);
	else if (ft_lstsize(*a) == 5)
		sort5(a, b);
	else
		sort(a, b);
}
