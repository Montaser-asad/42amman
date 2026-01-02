/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:25:24 by masad             #+#    #+#             */
/*   Updated: 2026/01/02 19:02:54 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **a, t_list **b)
{
	if ((*a)->content > (*b)->content)
		pb(b, a);
	else if ((*a)->content < (*b)->content)
	{
		pb(b, a);
		ra(a);
		pa(a, b);
		pa(a, b);
		sa(a);
		rrb(b);
	}
}

void	input2(void)
{
}

void	input3(void)
{
}

void	input4(void)
{
}

void	input5(void)
{
}

void	push_swap(int n)
{
	t_list		*a;
	t_list		*b;
	t_list		*t;

	a = NULL;
	b = NULL;
	t = ft_lstnew(n);
	ft_lstadd_back(&a, t);
}

int	main(int argc, char const *argv[])
{
	int	i;

	i = 1;
	while (argc > 1 && argv[i])
	{
		if (!check_in(argv[i]) || !check_max(argv[i]))
			return (-1);
		else
			i++;
	}
	if (!check_dup(argv + 1))
		return (-1);
	i = 1;
	while (argv[i])
	{
		push_swap(ft_atoi(argv[i]));
		i++;
	}
	return (0);
}
