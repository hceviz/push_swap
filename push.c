/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:21:39 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/21 11:46:49 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_connections(Stack *node, Stack **to)
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

void	push(Stack **from, Stack **to)
{
	Stack	*node;

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

void	pa(Stack **b, Stack **a, bool print)
{
	push(b, a);
	if (print == true)
		ft_putstr("pa\n");
}

void	pb(Stack **a, Stack **b, bool print)
{
	push(a, b);
	if (print == true)
		ft_putstr("pb\n");
}
