// #include "libft/libft.h"
#include <stdio.h>

void	push_swap(const char *n)
{
	printf("%s\n", n);
}

int	main(int argc, char const *argv[])
{
	int	i;

	i = 0;
	argv++;
	while (argc > 1 && *argv)
	{
		push_swap(*argv);
		argv++;
	}
	return (0);
}
