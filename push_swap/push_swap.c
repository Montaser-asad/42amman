/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <masad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:25:24 by masad             #+#    #+#             */
/*   Updated: 2026/01/20 16:55:39 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubsort(int *array, int size)
{
	int	i;
	int	j;
	int	t;

	j = 0;
	while (j < size - 1)
	{
		i = 0;
		while (i < size - 1 - j)
		{
			if (array[i] > array[i + 1])
			{
				t = array[i];
				array[i] = array[i + 1];
				array[i + 1] = t;
			}
			i++;
		}
		j++;
	}
}

static void	give_index(t_list **node, int *array, int sizeofls)
{
	int		i;
	t_list	*t;

	t = *node;
	while (*node)
	{
		i = -1;
		while (++i < sizeofls)
			if ((*node)->content == array[i])
				(*node)->index = i;
		(*node) = (*node)->next;
	}
	free(array);
	(*node) = t;
}

void	sort_i(t_list **node)
{
	t_list	*t;
	int		*array;
	int		i;
	int		sizeofls;

	t = *node;
	i = -1;
	sizeofls = ft_lstsize(*node);
	array = malloc(sizeof(int) * sizeofls);
	if (!array)
		return ;
	while (++i < sizeofls)
	{
		array[i] = (*node)->content;
		*node = (*node)->next;
	}
	(*node) = t;
	bubsort(array, sizeofls);
	give_index(node, array, sizeofls);
}

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
		if (!t && free_list(&a))
			return ;
		ft_lstadd_back(&a, t);
		i++;
	}
	if (ft_lstsize(a) < 6)
		short_sort(&a, &b);
	else
		sort(&a, &b);
	free_list(&a);
}

int	main(int argc, char const *argv[])
{
	char	**split;

	split = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (-1);
	else if (argv++ && argc == 2)
	{
		split = ft_split(*argv, ' ');
		if (!split)
			return (-1);
		argv = (char const **)split;
	}
	return (handle_input(argv, split));
}
