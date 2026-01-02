/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:25:29 by masad             #+#    #+#             */
/*   Updated: 2025/12/28 20:46:33 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	doit(a, NULL);
}
void	sb(t_list **b)
{
	doit(NULL, b);
}
void	ss(t_list **a, t_list **b)
{
	doit(a, b);
}

void	doit(t_list **a, t_list **b)
{
	int		temp;
	t_list	*t;

	if (b != NULL)
	{
		t = (*b);
		t = t->next;
		temp = t->content;
		t->content = (*b)->content;
		(*b)->content = temp;
	}
	if (a != NULL)
	{
		t = (*a);
		t = t->next;
		temp = t->content;
		t->content = (*a)->content;
		(*a)->content = temp;
	}
	if (b != NULL && a == NULL)
		write(1, "sb\n", 3);
	if (b == NULL && a != NULL)
		write(1, "sa\n", 3);
	if (b != NULL && a != NULL)
		write(1, "ss\n", 3);
}

void	doit(t_list **a, t_list **b)
{
	int		temp;
	t_list	*t;

	if (a && *a && (*a)->next)
	{
		t = (*a)->next;
		temp = t->content;
		t->content = (*a)->content;
		(*a)->content = temp;
	}
	if (b && *b && (*b)->next)
	{
		t = (*b)->next;
		temp = t->content;
		t->content = (*b)->content;
		(*b)->content = temp;
	}
	if (a && b)
		write(1, "ss\n", 3);
	else if (a)
		write(1, "sa\n", 3);
	else if (b)
		write(1, "sb\n", 3);
}
