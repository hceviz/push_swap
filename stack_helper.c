/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 07:45:12 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/24 09:25:50 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	minisort(t_stack **a)
{
	t_stack	*highest_node;

	if (stacklen(*a) == 2)
		sa(a, true);
	highest_node = getmax(*a);
	if (*a == highest_node)
		r_both_ways(a, 'f', 'a', true);
	else if ((*a)->next == highest_node)
		r_both_ways(a, 'r', 'a', true);
	if ((*a)->value > (*a)->next->value)
		sa(a, true);
}

t_stack	*getlast(t_stack *stck)
{
	t_stack	*head;

	if (!stck)
		return (NULL);
	head = stck;
	while (stck->next != head)
		stck = stck->next;
	return (stck);
}

void	update_index(t_stack *stck)
{
	t_stack	*head;
	int		index;
	int		median;

	if (!stck)
		return ;
	head = stck;
	index = 0;
	median = stacklen(stck) / 2;
	while (stck)
	{
		if (index > median)
			stck->a_median = false;
		else
			stck->a_median = true;
		stck->index = index++;
		stck = stck->next;
		if (stck == head)
			break ;
	}
}

void	top_min(t_stack **a)
{
	while ((*a)->value != getmin(*a)->value)
	{
		if (getmin(*a)->a_median)
			r_both_ways(a, 'f', 'a', true);
		else
			r_both_ways(a, 'r', 'a', true);
	}
}
