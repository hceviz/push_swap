#include "pushswap.h"

void	swap(Stack **stck)
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