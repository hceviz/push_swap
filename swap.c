/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:52:41 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/17 10:28:24 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void swap(Stack **stck)
{
    if (!(*stck) || !(*stck)->next)
        return; // If list is empty or has only one element, do nothing

    Stack	*first;
    Stack	*second;
	int		index;

	first = *stck;
	second = first->next;
	index = 0;
    // Adjusting the links
    first->next = second->next;
    if (second->next) // If there's a third node, update its previous pointer
        second->next->prev = first;
    second->prev = first->prev;
    second->next = first;
    first->prev = second;
    if (second->prev) // If there was a previous node, update its next pointer
        second->prev->next = second;
	
	*stck = second; // Update the head of the list
	update_index(*stck);
}

//to avoid from creating extra print function, added boolean print param
void	sa(Stack	**a, bool print)
{
	swap(a);
	if (print == true)
		ft_putstr("sa\n");
}

void	sb(Stack	**b, bool print)
{
	swap(b);
	if (print == true)
		ft_putstr("sb\n");
}

void	ss(Stack **a, Stack **b, bool print)
{
	swap(a);
	swap(b);
	if (print == true)
		ft_putstr("ss\n");
}