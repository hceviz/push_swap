/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:39:21 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/16 14:10:35 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	reverse_rotate(Stack **stck)
{
	if (!*stck || (*stck)->next == *stck)
		return ;
	Stack	*new_tail;
	Stack	*temp;
	int		index;

	new_tail = (*stck)->prev->prev;
	*stck = (*stck)->prev;
	temp = *stck;
	index = 0;
	while (temp != new_tail)
	{
		temp->index = index++;
		temp = temp->next;
	}
	temp->index = index;
}

void	rra(Stack **a, bool print)
{
	reverse_rotate(a);
	if (print == true)
		printf("rra\n"); //CHANGE WITH YOUR PRINTF
}

void	rrb(Stack **b, bool print)
{
	reverse_rotate(b);
	if (print == true)
		printf("rrb\n"); //CHANGE WITH YOUR PRINTF
}

void	rrr(Stack **a, Stack **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print == true)
		printf("rrr\n"); //CHANGE WITH YOUR PRINTF
}