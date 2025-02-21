/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:00:08 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/21 12:25:28 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//DELETE THIS FUNC BEFOR PUSH
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
int	main(int ac, char **av)
{

	Stack	*a;
	Stack	*b;
	int		no_split;

	a = NULL;
	b = NULL;
	no_split = 1;
	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		ft_putstr("Missing parameters.\n");
		return (1);
	}
	else if (ac == 2)
	{
		av = split(av[1], ' ');
		no_split = 1;
	}
	stack_init(&a, av + no_split);
	if (!is_ascending(a))
	{
		if (stacklen(a) == 2)
			sa(&a, 1);
		else if (stacklen(a) == 3)
			minisort(&a);
		else
			megasort(&a, &b);
	}
	print_list(a);
	free_stack(&a);
}