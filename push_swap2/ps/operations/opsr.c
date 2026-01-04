/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opsr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:25:32 by masad             #+#    #+#             */
/*   Updated: 2026/01/04 19:44:03 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	doit(t_list **a, t_list **b)
{
	t_list	*t;

	if (a != NULL)
	{
		t = *a;
		*a = (*a)->next;
		t->next = NULL;
		ft_lstadd_back(a, t);
	}
	if (b != NULL)
	{
		t = *b;
		*b = (*b)->next;
		t->next = NULL;
		ft_lstadd_back(b, t);
	}
}
void	ra(t_list **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	doit(a, NULL);
	write(1, "ra\n", 3);
}
void	rb(t_list **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	doit(NULL, b);
	write(1, "rb\n", 3);
}
void	rr(t_list **a, t_list **b)
{
	if ((!b || !*b || !(*b)->next) || (!a || !*a || !(*a)->next))
		return ;
	doit(a, b);
	write(1, "rr\n", 3);
}
