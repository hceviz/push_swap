/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 07:45:12 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/17 10:08:19 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	stacklen(Stack *stck)
{
	Stack	*head;
	int		count;

	head = stck;
	if (!stck)
		return (0);
	if (stck->next == stck)
		return (1);
	stck = stck->next;
	count = 1;
	while (stck != head)
	{
		stck = stck->next;
		++count;
	}
	return (count);
}

Stack	*getmax(Stack *stck)
{
	int			highest;
	Stack		*highest_node;
	Stack		*head;

	if (NULL == stck)
		return (NULL);
	head = stck;
	highest = INT_MIN;
	highest_node = stck;
	if (stck->value > highest)
	{
		highest = stck->value;
		highest_node = stck;
	}
	stck = stck->next;
	while (stck != head)
	{
		if (stck->value > highest)
		{
			highest = stck->value;
			highest_node = stck;
		}
		stck = stck->next;
	}
	return (highest_node);
}

Stack	*getmin(Stack *stck)
{
	int			lowest;
	Stack		*lowest_node;
	Stack		*head;

	if (NULL == stck)
		return (NULL);
	head = stck;
	lowest = INT_MAX;
	lowest_node = stck;
	if (stck->value < lowest)
	{
		lowest = stck->value;
		lowest_node = stck;
	}
	stck = stck->next;
	while (stck != head)
	{
		if (stck->value < lowest)
		{
			lowest = stck->value;
			lowest_node = stck;
		}
		stck = stck->next;
	}
	return (lowest_node);
}

Stack	*getlast(Stack *stck)
{
	Stack	*head;

	if (!stck)
		return (NULL);
	head = stck;
	while (stck->next != head)
		stck = stck->next;
	return (stck);
}

void	update_index(Stack *stck)
{
	Stack	*head;
	int		index;

	if (!stck)
		return ;
	head = stck;
	index = 0;
	stck->index = index++;
	stck = stck->next;
	while (stck != head)
	{
		stck->index = index++;
		stck = stck->next;
	}
}