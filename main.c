#include "pushswap.h"

int	main(int ac, char **av)
{

	Stack	*a = NULL;
	Stack	*b = NULL;
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
	if (stacklen(a) == 1)
		printf("NULL"); // change with your printf
	if (!is_ascending(a))
	{
		if (stacklen(a) == 2)
			sa(&a, 1);
		else if (stacklen(a) == 3)
			minisort(&a);
		

	}
	/* push(&a, &b);
	push(&a, &b);
	print_list(b);
	printf("Is sorted : %d\n", is_ascending(b));
	printf("Len: %d\n", stacklen(b));
	printf("Last: %d\n", getlast(b)->value);
	printf("\nA\n");
	print_list(a);
	printf("Is sorted : %d\n", is_ascending(a));
	printf("Len: %d\n", stacklen(a));
	printf("Last: %d", getlast(a)->value); */
}