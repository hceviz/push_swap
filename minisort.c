#include "pushswap.h"

//if it fits ra, and sa. firstly makes ra and updates the order and if it fits, sa
//same for rra also.
//last if block has big impact
void	minisort(Stack **a)
{
	Stack	*highest_node;

	highest_node = getmax(*a);
	if (*a == highest_node)
		ra(a, true);
	else if ((*a)->next == highest_node)
		rra(a, true);
	if ((*a)->value > (*a)->next->value)
		sa(a, true);
}
