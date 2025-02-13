#include "pushswap.h"

Stack	*find_last_node(Stack **stck)
{
	Stack	*current;

	current = *stck;
	while(current)
		current = current->next;
	return (current);
}

int	stacklen(Stack **stck)
{
	Stack	*head;
	Stack	*current;
	int		count;

	count = 0;
	head = *stck;
	current = *stck;
	if (!(*stck))
		return (0);
	if (current->next == current)
		return (1);
	current = current->next;
	count++;
	while (current != head)
	{
		current = current->next;
		count++;
	}

	return (count);
}

int getmax(Stack **stck)
{
	Stack	*head;
	Stack	*current;
	int		max;

	max = 0;
	head = *stck;
	current = *stck;
	current = current->next;
	while (current != head)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}

	return (max);
}