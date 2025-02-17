#include "pushswap.h"

//check rra is allowed to use like that
void	push(Stack **from, Stack **to) //careful with variable names
{
	Stack	*node;

	if (!*from)
		return ;
	node = *from;
	*from = (*from)->next;
	if (*from == node)
		*from = NULL;
	else
		node->prev->next = 	*from;
	if (!*to)
	{
		*to = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->prev = (*to)->prev;
		node->next = *to;
		(*to)->prev->next = node;
		(*to)->prev = node;
		*to = node;
	}
	update_index(*to);
	update_index(*from);
}

void	pa(Stack  **b, Stack **a, bool print)
{
	push(b, a);
	if (print == true)
		ft_putstr("pa\n");
}

void	pb(Stack **a, Stack **b, bool print)
{
	push(a, b);
	if (print == true)
		ft_putstr("pb\n");
}
