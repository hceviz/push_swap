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

Stack	*getmax(Stack **stck)
{
	Stack	*head;
	Stack	*current;
	Stack	*max;

	max = 0;
	head = *stck;
	current = *stck;
	current = current->next;
	while (current != head)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}

	return (max);
}

Stack	*getmin(Stack **stck)
{
	Stack	*head;
	Stack	*current;
	Stack	*min;

	min = 0;
	head = *stck;
	current = *stck;
	current = current->next;
	while (current != head)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}

	return (min);
}

Stack	*getlast(Stack **stck)
{
	Stack	*head;
	Stack	*temp;

	head = *stck;
	temp = *stck;
	printf("%d Index: %d\n", temp->value, temp->index);
	temp = temp->next;
	while (temp != head)
	{
		printf("%d Index: %d\n", temp->value, temp->index);
		temp = temp->next;
	}
	return (temp->prev);
}
