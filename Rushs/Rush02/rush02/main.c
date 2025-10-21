/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:28:18 by masad             #+#    #+#             */
/*   Updated: 2025/02/22 21:28:21 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void	subarray(char *num, char *str);

int	input_checker(char *str)
{
	int	i;
	int	is_it_numbers;
	char	*input;
	
	i = 0;
	j = 0;
	is_it_numbers = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			is_it_numbers = 1;
			input[j] = str[i];
			j++;
			i++;
		}
		else if(str[i] == ' ' || str[i] == '	' || str[i] == '\n' )
			{
				is_it_numbers = 0;
				i++;
			}
		else
		{
			is_it_numbers = 0;
			break ;
		}
	}
	return (is_it_numbers);
}

int	main(int argc, char *argv[])
{
	if (argc == 2 && input_checker(argv[1]) == 1)
		subarray(argv[1], "./numbers.dict");
	else if (argc == 3 && input_checker(argv[2]) == 1)
		subarray(argv[2], argv[1]);
	else
	{
		write(1, "usage: rush-02 <dictionary> <integer>\n", 39);
		write(1, "if u didn't specify dictionary", 30);
		write(1, " the default will take place :)", 31);
	}
	return (0);
}
