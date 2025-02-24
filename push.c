/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:21:39 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/24 09:25:45 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_connections(t_stack *node, t_stack **to)
{
	if (!*to)
	{
		*to = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->prev = (*to)->prev;
		node->next = *to;
		(*to)->prev->next = node;
		(*to)->prev = node;
		*to = node;
	}
}

void	push(t_stack **from, t_stack **to)
{
	t_stack	*node;

	if (!*from)
		return ;
	node = *from;
	*from = (*from)->next;
	if (*from == node)
		*from = NULL;
	else
	{
		(*from)->prev = node->prev;
		node->prev->next = *from;
	}
	set_connections(node, to);
	update_index(*to);
	update_index(*from);
}

void	pa(t_stack **b, t_stack **a, bool print)
{
	push(b, a);
	if (print == true)
		ft_putstr("pa\n");
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (print == true)
		ft_putstr("pb\n");
}
