/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opsrr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:25:36 by masad             #+#    #+#             */
/*   Updated: 2026/01/03 20:07:08 by masad            ###   ########.fr       */
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
	doit(a, NULL);
	write(1, "rra\n", 3);
}
void	rrb(t_list **b)
{
	doit(NULL, b);
	write(1, "rrb\n", 3);
}
void	rrr(t_list **a, t_list **b)
{
	doit(a, b);
	write(1, "rrr\n", 3);
}
