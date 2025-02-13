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

int	is_sorted(Stack *stck) //ascending
{
	if (!stck)
		return (0);
	while (stck->next)
	{
		if (stck->value > stck->next->value)
			return (-1);
		stck = stck->next;
	}
	return (1);
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