/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opsp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:25:30 by masad             #+#    #+#             */
/*   Updated: 2026/01/15 16:56:50 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **a, t_list **b)
{
	t_list	*t;

	if (!b || !*b)
		return ;
	t = *b;
	*b = (*b)->next;
	t->next = NULL;
	ft_lstadd_front(a, t);
	write(1, "pa\n", 3);
}

void	pb(t_list **b, t_list **a)
{
	t_list	*t;

	if (!a || !*a)
		return ;
	t = *a;
	*a = (*a)->next;
	t->next = NULL;
	ft_lstadd_front(b, t);
	write(1, "pb\n", 3);
}
