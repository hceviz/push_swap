/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 07:45:12 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/21 12:25:25 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	minisort(Stack **a)
{
	Stack	*highest_node;

	highest_node = getmax(*a);
	if (*a == highest_node)
		rotate_both_ways(a, 'f', 'a', true);
	else if ((*a)->next == highest_node)
		rotate_both_ways(a, 'r', 'a', true);
	if ((*a)->value > (*a)->next->value)
		sa(a, true);
}

Stack	*getlast(Stack *stck)
{
	Stack	*head;

	if (!stck)
		return (NULL);
	head = stck;
	while (stck->next != head)
		stck = stck->next;
	return (stck);
}

void	update_index(Stack *stck)
{
	Stack	*head;
	int		index;
	int		median;

	if (!stck)
		return ;
	head = stck;
	index = 0;
	median = stacklen(stck) / 2; //consider the median location in case of float number 5/2
	while (stck)
	{
		if (index > median)
			stck->a_median = false;
		else
			stck->a_median = true;
		stck->index = index++;
		stck = stck->next;
		if (stck == head)
			break;
	}
}

int is_in_stack(Stack *stack, Stack *node) //DELETE FROM HERE AND HEADER BEFORE PUSH 
{
	Stack *tmp = stack;
	if (!stack || !node)
		return (0);
	while (tmp)
	{
		if (tmp == node)
			return (1);
		tmp = tmp->next;
		if (tmp == stack)  // If stack is circular, avoid infinite loop
			break;
	}
	return (0);
}

void	top_min(Stack **a)
{
	//printf("Top min block\n");
	while((*a)->value != getmin(*a)->value)
	{
		if (getmin(*a)->a_median)
			rotate_both_ways(a, 'f', 'a', true);
		else
			rotate_both_ways(a, 'r', 'a', true);
	}
}