/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opsp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:25:30 by masad             #+#    #+#             */
/*   Updated: 2026/01/03 19:54:36 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	t_list	*t;

	t = ft_lstnew(n);
	t->next = *node;
	*node = t;
}
void	pa(t_list **a, t_list **b)
{
	if (!b || !*b)
		return ;
	push(a, pop(b));
}
void	pb(t_list **b, t_list **a)
{
	if (!a || !*a)
		return ;
	push(b, pop(a));
}