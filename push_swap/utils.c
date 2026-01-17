/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:40:00 by masad             #+#    #+#             */
/*   Updated: 2026/01/15 20:31:07 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

int	find_min(t_list *a)
{
	int	min;
	int	idx;
	int	i;

	min = a->content;
	idx = 1;
	i = 1;
	while (a)
	{
		if (a->content < min)
		{
			min = a->content;
			idx = i;
		}
		a = a->next;
		i++;
	}
	return (idx);
}

void	put_min_top(t_list **a)
{
	int	size;
	int	p;

	size = ft_lstsize((*a));
	p = find_min(*a);
	if (p == 1)
		return ;
	else if (p == 2)
		sa(a);
	else if (p == 3)
	{
		ra(a);
		ra(a);
	}
	else if (p == 4 && size == 4)
		rra(a);
	else if (p == 4 && size == 5)
	{
		rra(a);
		rra(a);
	}
	else if (p == 5 && size == 5)
		rra(a);
}

void	free_list(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
