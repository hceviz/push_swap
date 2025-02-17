/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:38:44 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/17 11:06:59 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(Stack **stck)
{
	if (!*stck || (*stck)->next == *stck)
		return ;
	*stck = (*stck)->next;
	update_index(*stck);
}

void	ra(Stack **a, bool print)
{
	rotate(a);
	if (print == true)
		ft_putstr("ra\n");
}

void	rb(Stack **b, bool print)
{
	rotate(b);
	if (print == true)
		ft_putstr("rb\n");
}

void	rr(Stack **a, Stack **b, bool print)
{
	rotate(a);
	rotate(b);
	if (print == true)
		ft_putstr("rr\n");
}