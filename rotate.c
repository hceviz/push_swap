/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:38:44 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/24 09:25:47 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	r_both_ways(t_stack **stck, char direction, char name, bool print)
{
	if (!*stck || (*stck)->next == *stck)
		return ;
	if (direction == 'f')
	{
		*stck = (*stck)->next;
		if (print)
		{
			if (name == 'a')
				ft_putstr("ra\n");
			else if (name == 'b')
				ft_putstr("rb\n");
		}
	}
	else if (direction == 'r')
	{
		*stck = (*stck)->prev;
		if (print)
		{
			if (name == 'a')
				ft_putstr("rra\n");
			else if (name == 'b')
				ft_putstr("rrb\n");
		}
	}
	update_index(*stck);
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	r_both_ways(a, 'f', 0, false);
	r_both_ways(b, 'f', 0, false);
	if (print == true)
		ft_putstr("rr\n");
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	r_both_ways(a, 'r', 0, false);
	r_both_ways(b, 'r', 0, false);
	if (print == true)
		ft_putstr("rrr\n");
}
