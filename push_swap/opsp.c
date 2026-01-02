/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opsp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:25:30 by masad             #+#    #+#             */
/*   Updated: 2025/12/28 20:29:00 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b)
{
}
void	pb(t_list **b, t_list **a)
{
	push(*b, 50);
}
int	pop(t_list **node)
{
	t_list	*t;
	int		r;

	t = *node;
	(*node) = (*node)->next;
	r = t->content;
	free(t);
	t = NULL;
	return (r);
}

void	push(t_list **node, int n)
{
	t_list *t;

	t = ft_lstnew(n);
	t->next = *node;
	*node = t;
}