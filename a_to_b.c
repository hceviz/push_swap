/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:53:15 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/21 11:35:14 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

Stack	*find_closest_smaller(Stack *b, int a_value)
{
	Stack	*current_b;
	Stack	*target_node;
	int		closer_num;

	closer_num = INT_MIN;
	current_b = b;
	target_node = NULL;
	while (1)
	{
		if (a_value > current_b->value && current_b->value > closer_num)
		{
			closer_num = current_b->value;
			target_node = current_b;
		}
		current_b = current_b->next;
		if (current_b == b)
			break ;
	}
	return (target_node);
}

void	set_target_for_a(Stack *a, Stack *b)
{
	Stack	*target_node;
	Stack	*a_head;

	a_head = a;
	while (a)
	{
		target_node = find_closest_smaller(b, a->value);
		if (target_node)
			a->target = target_node;
		else
			a->target = getmax(b);
		a = a->next;
		if (a == a_head)
			break ;
	}
}

void	calculate_cost(Stack *a, Stack *b)
{
	Stack	*a_head;
	int		len_a;
	int		len_b;

	len_a = stacklen(a);
	len_b = stacklen(b);
	a_head = a;
	while (a)
	{
		a->cost = a->index;
		if (!(a->a_median))
			a->cost = len_a - (a->index);
		if (a->target->a_median)
			a->cost += a->target->index;
		else
			a->cost += len_b - (a->target->index);
		a = a->next;
		if (a == a_head)
			break ;
	}
}

//anyway it will find cheapest
void	set_cheapest(Stack *a)
{
	Stack	*a_head;
	Stack	*cheapest_node;
	int		cheapest;

	if (!a)
		return ;
	a_head = a;
	cheapest = INT_MAX;
	while (a)
	{
		if (a->cost < cheapest)
		{
			cheapest = a->cost;
			cheapest_node = a;
		}
		a = a->next;
		if (a == a_head)
			break ;
	}
	cheapest_node->is_cheapest = true;
}

void	tune_nodes_a(Stack *a, Stack *b)
{
	update_index(a);
	update_index(b);
	set_target_for_a(a, b);
	calculate_cost(a, b);
	set_cheapest(a);
}
