#include "pushswap.h"

Stack	*create_node(int value)
{
	Stack	*node;

	node = (Stack *)malloc(sizeof(Stack));
	if (!node) exit(EXIT_FAILURE);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);	
}

void	add_to_list(Stack **head, int value)
{
	Stack	*new_node = create_node(value);
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = head;
		new_node->prev = head;
	}
	else
	{
		Stack	*tail;
		tail = (*head)->prev;
		while (tail->next)
			tail = tail->next;
		tail->next = new_node;
		new_node->prev = tail;
	}
}