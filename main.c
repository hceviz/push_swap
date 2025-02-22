/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:00:08 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/22 16:08:49 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//DELETE THIS FUNC BEFOR PUSH
/* void	print_list(t_stack *stck)
{
	t_stack	*head;
	t_stack	*temp;

	head = stck;
	temp = stck;
	printf("%d Index: %d\n", temp->value, temp->index);
	temp = temp->next;
	while (temp != head)
	{
		printf("%d Index: %d\n", temp->value, temp->index);
		temp = temp->next;
	}
} */

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 0 || (ac == 2 && !av[1]))
		return (1);
	else if (ac == 2)
	{
		av = split(av[1], ' ');
	}
	stack_init(&a, av + 1);
	if (!is_ascending(a))
	{
		if (stacklen(a) == 2)
			sa(&a, 1);
		else if (stacklen(a) == 3)
			minisort(&a);
		else
			megasort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
