#include "pushswap.h"

int	main(int ac, char **av)
{

	Stack	*a = NULL;
	int		no_split;

	no_split = 1;

	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		printf("Main edge case error");
		return (1);
	}
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		no_split = 0;
	}
	stack_init(&a, av);
	print_list(&a); 
/* 	printf("%d\n", is_num("-a"));
	printf("%d\n", is_num("a"));
	printf("%d\n", is_num("-123"));
	printf("%d\n", is_num("+123"));
	printf("%d\n", is_num("123")); */

}