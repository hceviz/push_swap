/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 07:45:12 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/20 12:19:41 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void	prep_push(Stack **stck, Stack *node_for_top, char stack_name)
{
	while (*stck != node_for_top)
	{
		if (stack_name == 'a')
		{
			if (node_for_top->a_median)
				ra(stck, false);
			else
				rra(stck, false);
		}
		else if (stack_name == 'b')
		{
			if (node_for_top->a_median)
				rb(stck, false);
			else
				rrb(stck, false);
		}
	}
}