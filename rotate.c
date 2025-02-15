#include "pushswap.h"

/* void	rotate(Stack **stck)
{
	Stack	*first;
	Stack	*last;
	Stack	*new_first;
	int		index;

	first = *stck;
	last = (*stck)->prev;
	new_first = (*stck)->next;

	last->next = first;
	first->prev = last;
	first->next = new_first;
	new_first->prev = first;

	*stck = new_first;

	index = first->index;
    first->index = new_first->index;
    new_first->index = index;
} */

void	rotate(Stack **stack) //Define a function that rotates the stack's top node to the bottom of the stack
{
	Stack	*last_node; //To store a pointer to the last node of a stack
	int		index;

	if (!*stack || !(*stack)->next) //Check if the stack is empty, or if there's one node
		return ;
	last_node = (*stack)->prev; 
	last_node->next = *stack; //Assign to the last node, its `next` attribute as the top node, effectively setting the current top node as the last node
	*stack = (*stack)->next; //Assign to the pointer of the top node, the node after it (second from the top)
	(*stack)->prev = NULL; //Complete setting the current top node by detaching it from its previous top node
	last_node->next->prev = last_node; //Reconnect the second node's prev pointer to point to what was previously the last node in the stack
	last_node->next->next = NULL; //Assign to the `next` attribute of the current last node, `NULL` effectively setting it as the current last node, and properly null terminating the stack
	index = 
}		


void	ra(Stack **a, bool print)
{
	rotate(a);
	if (print == true)
		printf("ra\n");
}
void	rb(Stack **b, bool print)
{
	rotate(b);
	if (print == true)
		printf("rb\n");
}

void	rr(Stack **a, Stack **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print == true)
		printf("rr\n");
}