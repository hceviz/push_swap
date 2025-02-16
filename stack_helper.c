#include "pushswap.h"

Stack	*find_last_node(Stack *stck)
{
	if(!stck)
		return (NULL);
	while(stck->next)
		stck = stck->next;
	return (stck);
}

int	stacklen(Stack *stck)
{
	Stack	*head;
	int		count;

	head = stck;
	if (!stck)
		return (0);
	if (stck->next == stck)
		return (1);
	stck = stck->next;
	count = 1;
	while (stck != head)
	{
		stck = stck->next;
		++count;
	}
	return (count);
}

Stack	*getmax(Stack *stck)
{
	long	max;
	Stack	*max_node;
	Stack	*head;

	head = stck;
	max = LONG_MIN;
	while (stck != head)
	{
		if (stck->value > max)
		{
			max = stck->value;
			max_node = stck;
		}
		stck = stck->next;
	}
	return (max_node);
}

Stack	*getmin(Stack *stck)
{
	long	min;
	Stack	*min_node;
	Stack	*head;

	head = stck;
	min = LONG_MAX;
	while (stck != head)
	{
		if (stck->value < min)
		{
			min = stck->value;
			min_node = stck;
		}
		stck = stck->next;
	}
	return (min_node);
}

Stack	*getlast(Stack *stck)
{
	Stack	*head;

	head = stck;
	while (stck != head)
		stck = stck->next;
	return (stck);
}
