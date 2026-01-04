/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:25:24 by masad             #+#    #+#             */
/*   Updated: 2026/01/04 20:21:42 by masad            ###   ########.fr       */
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
		short_sort(&a , &b);
	else 
		sort (&a , &b);
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
