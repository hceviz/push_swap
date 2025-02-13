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
		av = split(av[1], ' ');
		no_split = 1;
	}
	stack_init(&a, av + no_split);
	if (is_sorted(a)== -1)
	{
		if (stacklen(a) <= 3) //for 2,3
			minisort(&a);
	} 
	print_list(&a);
	printf("Stack len:%d", stacklen(&a));
	free(a);
/* 	printf("%d\n", is_num("-a"));
	printf("%d\n", is_num("a"));
	printf("%d\n", is_num("-123"));
	printf("%d\n", is_num("+123"));
	printf("%d\n", is_num("123")); */

}