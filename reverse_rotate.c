/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:39:21 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/17 10:29:44 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	reverse_rotate(Stack **stck)
{
	if (!*stck || (*stck)->next == *stck)
		return ;
	*stck = (*stck)->prev;
	update_index(*stck);
}

void	rra(Stack **a, bool print)
{
	reverse_rotate(a);
	if (print == true)
		ft_putstr("rra\n");
}

void	rrb(Stack **b, bool print)
{
	reverse_rotate(b);
	if (print == true)
		ft_putstr("rrb\n");
}

void	rrr(Stack **a, Stack **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print == true)
		ft_putstr("rrr\n");
}