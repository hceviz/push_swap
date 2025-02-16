#include "pushswap.h"

/* void	swap(Stack **stck)
{
	if (!(*stck) || !(*stck)->next)
	{
		//to make the swap we need at least 2 nodes
		return ;
	}
	(*stck)->next = (*stck)->next->next;
	(*stck)->prev = (*stck)->next->prev;
	(*stck)->next->next->prev = (*stck);
	(*stck)->next->next = (*stck);
	(*stck)->next->prev = (*stck)->prev;
	(*stck)->prev->next = (*stck)->next;
	*stck = (*stck)->next;
} */

void swap(Stack **stck)
{
    if (!(*stck) || !(*stck)->next)
        return; // If list is empty or has only one element, do nothing

    Stack	*first;
    Stack	*second;
	int		index;

	first = *stck;
	second = first->next;
	index = 0;
    // Adjusting the links
    first->next = second->next;
    if (second->next) // If there's a third node, update its previous pointer
        second->next->prev = first;
    second->prev = first->prev;
    second->next = first;
    first->prev = second;
    if (second->prev) // If there was a previous node, update its next pointer
        second->prev->next = second;
	
	*stck = second; // Update the head of the list
	index = first->index;
	first->index = second->index;
	second->index = index;
}


//to avoid from creating extra print function, added boolean print param
void	sa(Stack	**a, bool print)
{
	swap(a);
	if (print == true)
		printf("sa\n"); //CHANGE WITH YOUR PRINTF
}

void	sb(Stack	**b, bool print)
{
	swap(b);
	if (print == true)
		printf("sb\n"); //CHANGE WITH YOUR PRINTF
}

void	ss(Stack **a, Stack **b, bool print)
{
	swap(a);
	swap(b);
	if (print == true)
		printf("ss\n"); //CHANGE WITH YOUR PRINTF
}