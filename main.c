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
	/* if (stacklen(a) == 1)
		printf("NULL"); // change with your printf
	if (!is_ascending(a))
	{
		if (stacklen(a) == 2)
			sa(&a, 1);
		else if (stacklen(a) == 3)
			minisort(&a);
	} */
	//printf("Index: %d\nValue: %d\n--------", a->index, a->value);
	/* printf("\nInitial List\n-------------\n");
	print_list(a);
	printf("\nFirst push\n--------------\n");
	push(&a, &b);
	print_list(a);
	printf("\nSecond push\n--------------\n");
	push(&a, &b);
	print_list(a);
	printf("\nAfter pushin first 2 nodes\n--------------\n");
	set_target_for_a(a, b);
	calculate_cost(a, b);
	push(&a, &b);
	printf("\nThird push\n--------------\n");
	print_list(a);
	set_target_for_a(a, b);
	calculate_cost(a, b);
	push(&a, &b);
	printf("\nFortg push\n--------------\n");
	print_list(a); */

	push(&a, &b);
	push(&a, &b);
	//push(&a, &b);
	Stack *a_head = a;
	set_cheapest(a);
	while (a)
	{
		set_target_for_a(a, b);
		calculate_cost(a, b);
		printf("Index : %d Value: %d Target: %d PushCost: %d IsCheapest: %d\n----------------------\n", a->index, a->value, a->target->value, a->cost, a->is_cheapest);
		a = a->next;
		if (a == a_head)
			break;
	}
	printf("\nB\n--------------\n");
	print_list(b);
	printf("\nTarget for A's first node %d is %d\n", a->value, a->target->value);
	printf("Push cost of %d : %d\nTarget : %d\n------------\n", a->value, a->cost, a->target->value);
}