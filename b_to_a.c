/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:54:26 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/21 12:25:30 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

Stack	*find_closest_bigger(Stack *a, int b_value)
{
	Stack	*current_a;
	Stack	*target_node;
	int		closer_num;

	closer_num = INT_MAX;
	current_a = a;
	target_node = NULL;
	while (1)
	{
		if (b_value < current_a->value && current_a->value < closer_num)
		{
			closer_num = current_a->value;
			target_node = current_a;
		}
		current_a = current_a->next;
		if (current_a == a)
			break ;
	}
	return (target_node);
}

void	set_target_for_b(Stack *a, Stack *b)
{
	Stack	*target_node;
	Stack	*b_head;

	b_head = b;
	while (b)
	{
		target_node = find_closest_bigger(a, b->value);
		if (target_node)
			b->target = target_node;
		else
			b->target = getmin(a);
		b = b->next;
		if (b == b_head)
			break ;
	}
}

void	tune_nodes_b(Stack *a, Stack *b)
{
	update_index(a);
	update_index(b);
	set_target_for_b(a, b);
}
