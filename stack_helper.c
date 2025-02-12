#include "pushswap.h"

Stack	*find_last_node(Stack **stck)
{
	Stack	*current;

	current = *stck;
	while(current)
		current = current->next;
	return (current);
}