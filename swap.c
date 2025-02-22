/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 08:52:41 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/22 14:05:38 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_stack **stck)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*stck) || !(*stck)->next)
		return ;
	first = *stck;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	if (second->prev)
	{
		second->prev->next = second;
	}
	*stck = second;
	update_index(*stck);
}

//to avoid from creating extra print function, added boolean print param
void	sa(t_stack	**a, bool print)
{
	swap(a);
	if (print == true)
		ft_putstr("sa\n");
}

void	sb(t_stack	**b, bool print)
{
	swap(b);
	if (print == true)
		ft_putstr("sb\n");
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (print == true)
		ft_putstr("ss\n");
}
