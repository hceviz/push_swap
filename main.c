#include "pushswap.h"

/* int	main(int ac, char **av)
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
	if (stacklen(a) == 1)
		printf("NULL"); // change with your printf
	if (is_ascending(a) == -1)
	{
		if (stacklen(a) == 2)
			sa(&a, 1);
		else if (stacklen(a) == 3)
			minisort(&a);
	}
	//print_list(&a);
	printf("Is sorted : %d\n", is_ascending(a));
	printf("Len: %d\n", stacklen(a));
	
} */

int	main(int argc, char **argv) //Define a program that takes in a random input if numbers and sorts them in ascending order
{
	Stack	*a; //To store a pointer to stack `a`
	Stack	*b; //To store a pointer to stack `b`

	a = NULL; //Set both pointers to NULL to avoid undefined behaviour
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0])) //Check for incorrect argument counts or if the 2 argument is `0`
		return (1);
	else if (argc == 2) //Check if the argument count is 2 and the 2nd is not empty, this implies a string
		argv = split(argv[1], ' '); //Call ``split()` to extract each substring
	stack_init(&a, argv + 1); //Initiate stack `a`, which also handles errors
	if (!is_ascending(a)) //Check if the stack is not sorted
	{
		if (stacklen(a) == 3 && getmax(a)->index != 2)
			minisort(&a);
	}
	print_list(a);
	printf("Len: %d\n", stacklen(a));
	printf("Is sorted: %d\n", is_ascending(a));
	return (0);
}