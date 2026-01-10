/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:25:24 by masad             #+#    #+#             */
/*   Updated: 2026/01/08 19:00:49 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>




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
	if (ft_lstsize(a) < 6)
		short_sort(&a, &b);
	// else
	// 	sort(&a, &b);
	while (a)
	{
		printf("%d ", a->content);
		a = a->next;
	}
}

int	main(int argc, char const *argv[])
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (-1);
	else if (argv++ && argc == 2)
		argv = (char const **)(ft_split(argv[0], ' '));
	if (!parse(argv))
	{
		if (parse(argv) == 2)
			return (0);
		push_swap(argv);
	}
	return (1);
}
