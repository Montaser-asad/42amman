/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:25:24 by masad             #+#    #+#             */
/*   Updated: 2026/01/03 20:14:11 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// void	sort(t_list **a, t_list **b)
// {
// 	if ((*a)->content > (*b)->content)
// 		pb(b, a);
// 	else if ((*a)->content < (*b)->content)
// 	{
// 		pb(b, a);
// 		ra(a);
// 		pa(a, b);
// 		pa(a, b);
// 		sa(a);
// 		rrb(b);
// 	}
// }

// void	input2(void)
// {
// }

// void	input3(void)
// {
// }

// void	input4(void)
// {
// }

// void	input5(void)
// {
// }

void	push_swap(char const *input[])
{
	int		i;
	t_list	*a;
	t_list	*b;
	t_list	*t;

	i = 0;
	b = NULL;
	a = NULL;
	while (input[i])
	{
		t = ft_lstnew(ft_atol(input[i]));
		ft_lstadd_back(&a, t);
		i++;
	}
	pb(&b, &a);
	pb(&b, &a);
	ss(&a, &b);
	printf("\nthis is a\n");
	while (a)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
	printf("\nthis is b\n");
	while (b)
	{
		printf("%d\n", b->content);
		b = b->next;
	}
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
	push_swap(argv + 1);
	return (0);
}
