/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opsr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:25:32 by masad             #+#    #+#             */
/*   Updated: 2025/12/30 17:58:01 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	doit(a, NULL);
}
void	rb(t_list **b)
{
	doit(NULL, b);
}
void	rr(t_list *a, t_list *b)
{
	doit(a, b);
}
void	doit(t_list **a, t_list **b)
{
	t_list	*t;
	t_list	*p;

	if (a != NULL)
	{
		t = *b;
		while (t->next)
			t = t->next;
		p = t;
		p = p->next;
		t->next = NULL;
		ft_lstadd_front(b, p);
	}
	if (b != NULL)
	{
		t = *b;
		while (t->next)
			t = t->next;
		p = t;
		p = p->next;
		t->next = NULL;
		ft_lstadd_front(b, p);
	}
	if (a && b)
		write(1, "rr\n", 3);
	else if (a)
		write(1, "ra\n", 3);
	else if (b)
		write(1, "rb\n", 3);
}
