#include "pushswap.h"

int	is_num(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(char **av, long num)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (av[i])
	{
		if (ft_atol(av[i]) == num)
			count++;
		i++;
	}
	if (count > 1)
		return (1);
	return (0);
} 

void	free_stack(Stack **stck)
{
	Stack	*temp;
	Stack	*current;	

	if (!stck || !(*stck))
		return ;
	current = *stck;

	(*stck)->prev->next = NULL; //to break the circle
	while (current)
	{
		temp = current->next;
		//current->value = 0;
		free(current);
		current = temp;
		printf("Freed\n");
	}
	*stck = NULL;
} 

void	free_and_exit(Stack **stck)
{
	free_stack(stck);
	printf("Error\n"); //change with your printf
	exit(EXIT_FAILURE);
}