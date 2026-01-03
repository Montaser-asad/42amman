/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:25:29 by masad             #+#    #+#             */
/*   Updated: 2026/01/03 20:13:28 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	doit(t_list **a, t_list **b)
{
	t_list	*t;

	if (a && *a && (*a)->next)
	{
		t = (*a)->next;
		(*a)->next = NULL;
		(*a)->next = t->next;
		t->next = NULL;
		ft_lstadd_front(a, t);
	}
	if (b && *b && (*b)->next)
	{
		t = (*b)->next;
		(*b)->next = NULL;
		(*b)->next = t->next;
		t->next = NULL;
		ft_lstadd_front(b, t);
	}
}
void	sa(t_list **a)
{
	doit(a, NULL);
	write(1, "sa\n", 3);
}
void	sb(t_list **b)
{
	doit(NULL, b);
	write(1, "sb\n", 3);
}
void	ss(t_list **a, t_list **b)
{
	doit(a, b);
	write(1, "ss\n", 3);
}
