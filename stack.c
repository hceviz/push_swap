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
			printf("error 1\n%s", av[i]);
			free_and_exit(stck);
		} //checks for -a, a, number
		num = ft_atol(av[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			printf("error 2");
			free_and_exit(stck);
		}
		if (is_duplicate(av, num)) //num type is long
		{
			printf("error 3");
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
	}
	else
	{
		Stack	*tail;

		tail = (*stck)->prev;
		tail->next = node;
		node->prev = tail;
		node->next = (*stck);
		(*stck)->prev = node;
	}
}

//CHANGE WITH YOUR PRINTF
void	print_list(Stack **stck)
{
	Stack	*head;
	Stack	*temp;

	head = *stck;
	temp = *stck;
	printf("%d\n", temp->value);
	temp = temp->next;
	while (temp != head)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
}