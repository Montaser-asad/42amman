/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:25:24 by masad             #+#    #+#             */
/*   Updated: 2025/12/30 18:36:03 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(const char **n)
{
	int	i;
	int	j;

	i = 0;
	while (n[i])
	{
		j = i + 1;
		while (n[j])
		{
			if (ft_atoi(n[i]) == ft_atoi(n[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_in(const char *n)
{
	if (*n == '-' || *n == '+')
		n++;
	while (*n)
	{
		if (*n >= '0' && *n <= '9')
			n++;
		else
			return (0);
	}
	return (1);
}

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

void	push_swap(const char *n)
{
	const char	*check;
	t_list		*a;
	t_list		*b;
	t_list		*t;

	check = n;
	a = NULL;
	b = NULL;
	t = ft_lstnew(ft_strdup(n));
	ft_lstadd_back(&a, t);
	while (a)
	{
		printf("%s\n", (char *)a->content);
		a = a->next;
	}
}

int	main(int argc, char const *argv[])
{
	int	i;

	i = 1;
	while (argc > 1 && argv[i])
	{
		if (!check_in(argv[i]))
			return (-1);
		else
			i++;
	}
	if (!check_dup(argv + 1))
		return (-1);
	i = 1;
	while (argv[i])
	{
		push_swap((argv[i]));
		i++;
	}
	return (0);
}
