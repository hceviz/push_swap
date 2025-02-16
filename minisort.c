#include "pushswap.h"

/* void	minisort(Stack **stck)
{
	Stack	*max;
	Stack	*min;

	max = getmax(*stck);
	min = getmin(*stck);
	if (max->index == 0)
	{
		ra(stck, true);
		if (min->index == 2)
			sa(stck, true);
	}
	else if (max->index == 1)
	{
		rra(stck, true);
		if (min->index == 0)
			sa(stck, true);
	}
	else if (max->index == 2 && min->index == 1)
		sa(stck, true);
} */

static Stack	*findhigh(Stack *stack)
{
	int				highest;
	Stack		*highest_node;
	Stack		*head;

	head = stack;
	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack->next != head)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	minisort(Stack **a)
{
	Stack	*highest_node;

	highest_node = findhigh(*a);
	if (*a == highest_node)
		ra(a, true);
	else if ((*a)->next == highest_node)
		rra(a, true);
	if ((*a)->value > (*a)->next->value)
		sa(a, true);
}
/* 
void	minisort(Stack **a) //Define a function that handles when stack `a` has three nodes, and sorts it
{
	Stack	*biggest_node; //To store a pointer to the biggest node in stack `a`

	biggest_node = getmax(*a);
	if (biggest_node == *a) //Check if the current node is the biggest
		ra(a, true); //If so, rotate the top node to the bottom of the stack
	else if ((*a)->next == biggest_node) //Check if the second node is the biggest
		rra(a, true); //If so, reverse rotate the bottom node, to the top of the stack
	if ((*a)->value > (*a)->next->value) //Check if the bottom node is the biggest, but the top node is higher than the second node
		sa(a, true); //If so, simply swap the top and second nodes
}  */