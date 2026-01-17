/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opsrr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:25:36 by masad             #+#    #+#             */
/*   Updated: 2026/01/15 16:57:32 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	doit(t_list **a, t_list **b)
{
	t_list	*t;
	t_list	*p;

	if (a != NULL)
	{
		t = *a;
		while (t->next && t->next->next)
			t = t->next;
		p = t->next;
		t->next = NULL;
		ft_lstadd_front(a, p);
	}
	if (b != NULL)
	{
		t = *b;
		while (t->next && t->next->next)
			t = t->next;
		p = t->next;
		t->next = NULL;
		ft_lstadd_front(b, p);
	}
}

void	rra(t_list **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	doit(a, NULL);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	doit(NULL, b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	if ((!b || !*b || !(*b)->next) || (!a || !*a || !(*a)->next))
		return ;
	doit(a, b);
	write(1, "rrr\n", 4);
}
