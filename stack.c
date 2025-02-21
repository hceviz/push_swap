/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:21:56 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/21 12:25:26 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stack_init(Stack **stck, char **av)
{
	long	num;
	int		i;

	i = 0;
	while (av[i])
	{
		if (!is_num(av[i]))
		{
			ft_putstr("Num type error\n");
			free_and_exit(stck);
		}
		num = ft_atol(av[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_putstr("INT range error\n");
			free_and_exit(stck);
		}
		if (is_duplicate(av, num))
		{
			ft_putstr("Duplicate error\n");
			free_and_exit(stck);
		}
		append_node(stck, (int)num);
		i++;
	}
}

void	append_node(Stack **stck, int value)
{
	Stack	*node;

	if (!stck)
		return ;
	node = malloc(sizeof(Stack));
	if (!node)
		return ;
	node->value = value;
	node->is_cheapest = false;
	if (!(*stck))
	{
		*stck = node;
		node->prev = node;
		node->next = node;
		node->index = 0;
	}
	else
	{
		(*stck)->prev->next = node;
		node->prev = (*stck)->prev;
		node->index = (*stck)->prev->index + 1;
		node->next = (*stck);
		(*stck)->prev = node;
	}
}

int	is_ascending(Stack *stck)
{
	Stack	*head;

	head = stck;
	if (stacklen(stck) == 1)
		return (1);
	if (stck->value > stck->next->value)
		return (0);
	else
		stck = stck->next;
	while (stck->next != head)
	{
		if (stck->value > stck->next->value)
			return (0);
		stck = stck->next;
	}
	return (1);
}

void	pop_node(Stack **stck)
{
	Stack	*node;
	Stack	*last;

	if (!*stck)
		return ;
	node = *stck;
	if ((*stck)->next == *stck)
		*stck = NULL;
	else
	{
		last = (*stck)->prev;
		*stck = (*stck)->next;
		(*stck)->prev = last;
		last->next = *stck;
	}
	free(node);
	update_index(*stck);
}

Stack	*get_cheapest(Stack	*a)
{
	Stack	*a_head;

	if (!a)
		return (NULL);
	a_head = a;
	while (a)
	{
		if (a->is_cheapest)
			return (a);
		a = a->next;
		if (a == a_head)
			break ;
	}
	return (NULL);
}
