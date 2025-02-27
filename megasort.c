/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megasort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:55:13 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/24 09:25:44 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	move_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->a_median && cheapest->target->a_median)
		revnormal_both(a, b, cheapest, 'n');
	else if (!cheapest->a_median && !cheapest->target->a_median)
		revnormal_both(a, b, cheapest, 'r');
	prep_push(a, cheapest, 'a');
	prep_push(b, cheapest->target, 'b');
	pb(a, b, true);
}

void	move_b(t_stack **a, t_stack **b)
{
	prep_push(a, (*b)->target, 'a');
	pa(b, a, true);
}

void	megasort(t_stack **a, t_stack **b)
{
	int		len_a;

	len_a = stacklen(*a);
	if (len_a-- > 3 && !is_ascending(*a))
		pb(a, b, true);
	if (len_a-- > 3 && !is_ascending(*a))
		pb(a, b, true);
	while (len_a-- > 3 && !is_ascending(*a))
	{
		tune_nodes_a(*a, *b);
		move_a(a, b);
	}
	minisort(a);
	while (*b)
	{
		tune_nodes_b(*a, *b);
		move_b(a, b);
	}
	update_index(*a);
	top_min(a);
}

void	revnormal_both(t_stack **a, t_stack **b, t_stack *cheapest, char r_type)
{
	while (*b != cheapest->target && *a != cheapest)
	{
		if (r_type == 'n')
			rr(a, b, true);
		else if (r_type == 'r')
			rrr(a, b, true);
	}
	update_index(*a);
	update_index(*b);
}

void	prep_push(t_stack **stck, t_stack *node_for_top, char stack_name)
{
	while (*stck != node_for_top)
	{
		if (stack_name == 'a')
		{
			if (node_for_top->a_median)
				r_both_ways(stck, 'f', 'a', true);
			else
				r_both_ways(stck, 'r', 'a', true);
		}
		else if (stack_name == 'b')
		{
			if (node_for_top->a_median)
				r_both_ways(stck, 'f', 'b', true);
			else
				r_both_ways(stck, 'r', 'b', true);
		}
	}
}
