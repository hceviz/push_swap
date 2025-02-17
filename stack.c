#include "pushswap.h"

void	stack_init(Stack **stck, char **av)
{
	long	num;
	int		i;

	i = 0;
	while (av[i])
	{
		if (!is_num(av[i]))
		{
			printf("Num type error\n%s", av[i]);
			free_and_exit(stck);
		} //checks for -a, a, number
		num = ft_atol(av[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			printf("INT range error\n");
			free_and_exit(stck);
		}
		if (is_duplicate(av, num)) //num type is long
		{
			printf("Duplicate error\n");
			free_and_exit(stck);
		}
		append_node(stck, (int)num);
		i++;
	}
	printf("Stack init success\n");
}

void	append_node(Stack **stck, int value)
{
	Stack	*node;

	if (!stck)
		return ;
	node = malloc(sizeof(Stack));
	if (!node)
		return ;
	node->value = value;
	node->is_cheapest = false;
	if (!(*stck))
	{
		*stck = node;
		node->prev = node;
		node->next = node; //CHECK IS IT CORRECT
		node->index = 0;
	}
	/* else
	{
		Stack	*tail;

		tail = (*stck)->prev;
		tail->next = node;
		node->prev = tail;
		node->index = tail->index + 1;
		node->next = (*stck);
		(*stck)->prev = node;
	} */
	 else
	{
		(*stck)->prev->next = node;
		node->prev = (*stck)->prev;
		node->index = (*stck)->prev->index + 1;
		node->next = (*stck);
		(*stck)->prev = node;
	}
}

int	is_ascending(Stack *stck) //ascending
{
	Stack	*head;

	head = stck;
	if (stacklen(stck) == 1)
		return (1);
	if (stck->value > stck->next->value)
		return (0);
	else
		stck = stck->next;
	while (stck->next != head)
	{
		if (stck->value > stck->next->value)
			return (0);
		stck = stck->next;
	}
	return (1);
}

void	pop_node(Stack **stck)
{
	Stack	*node;
	Stack	*last;

	if (!*stck)
		return ;
	node = *stck;
	if ((*stck)->next == *stck)
		*stck = NULL;
	else
	{
		last = (*stck)->prev;
		*stck = (*stck)->next;
		(*stck)->prev = last;
		last->next = *stck;
	}
	free(node);
	update_index(*stck);
}
//CHANGE WITH YOUR PRINTF
//delete the func before push
void	print_list(Stack *stck)
{
	Stack	*head;
	Stack	*temp;

	head = stck;
	temp = stck;
	printf("%d Index: %d\n", temp->value, temp->index);
	temp = temp->next;
	while (temp != head)
	{
		printf("%d Index: %d\n", temp->value, temp->index);
		temp = temp->next;
	}
}