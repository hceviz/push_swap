/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:38:44 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/16 18:04:29 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(Stack **stck)
{
	if (!*stck || (*stck)->next == *stck)
		return ;
	Stack	*first;
	Stack	*last;
	Stack	*temp;
	int		index;

	first = *stck;
	last = first->prev;
	*stck = first->next;
	last->next = first;
	first->prev = last;
	first->next = *stck;
	(*stck)->prev = first;
	temp = *stck;
	index = 0;
	while (temp != first)
	{
		temp->index = index++;
		temp = temp->next;
	}
	temp->index = index;
}

void	ra(Stack **a, bool print)
{
	rotate(a);
	if (print == true)
		printf("ra\n");
}

void	rb(Stack **b, bool print)
{
	rotate(b);
	if (print == true)
		printf("rb\n");
}

void	rr(Stack **a, Stack **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print == true)
		printf("rr\n");
}