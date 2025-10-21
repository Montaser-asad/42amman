/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   categorizer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 21:27:54 by masad             #+#    #+#             */
/*   Updated: 2025/02/22 21:28:01 by masad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	hundreds(char n, char *buffer_name);
void	tens(char n, char *buffer_name);
void	ones(char n, char *buffer_name);
void	mult(int cat, char *buffer_name);
void	read_file(char *str, char *num);
void	tash(char n, char m, char *buffer_name);

void	mult_next(int cat, char *buffer_name)
{
	else if (cat == 7)
		read_file(buffer_name, "1000000000000000000000");
	else if (cat == 8)
		read_file(buffer_name, "1000000000000000000000000");
	else if (cat == 9)
		read_file(buffer_name, "1000000000000000000000000000");
	else if (cat == 10)
		read_file(buffer_name, "1000000000000000000000000000000");
	else if (cat == 11)
		read_file(buffer_name, "1000000000000000000000000000000000");
	else if (cat == 12)
		read_file(buffer_name, "1000000000000000000000000000000000000");
}

void	mult(int cat, char *buffer_name)
{
	if (cat == 0)
		return ;
	else if (cat == 1)
		read_file(buffer_name, "1000");
	else if (cat == 2)
		read_file(buffer_name, "1000000");
	else if (cat == 3)
		read_file(buffer_name, "1000000000");
	else if (cat == 4)
		read_file(buffer_name, "1000000000000");
	else if (cat == 5)
		read_file(buffer_name, "1000000000000000");
	else if (cat == 6)
		read_file(buffer_name, "1000000000000000000");
	else
		mult_next(cat, buffer_name);
}

void	categorizer(char *chunk, int cat, char *buffer_name)
{
	int	len;

	len = 0;
	while (chunk[len] != '\0')
			len++;
		if ((len - 1) == 3)
		{
			hundreds(chunk[0], buffer_name);
			mult(cat, buffer_name);
			if (chunk[1] == '1')
				tash(chunk[1], chunk[2], buffer_name);
			else
			{
				tens(chunk[1], buffer_name);
				ones(chunk[2], buffer_name);
			}
		}
	else if ((len - 1) == 2)
	{
		if (chunk[0] == '1')
			tash(chunk[0], chunk[1], buffer_name);
		else
		{
			tens(chunk[0], buffer_name);
			ones(chunk[1], buffer_name);
		}
		mult(cat, buffer_name);
	}
	else if ((len - 1) == 1)
	{
		ones(chunk[0], buffer_name);
		mult(cat, buffer_name);
	}
}
