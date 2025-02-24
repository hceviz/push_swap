/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:21:56 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/24 09:25:52 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stack_init(t_stack **stck, char **av)
{
	long	num;
	int		i;

	i = 0;
	while (av[i])
	{
		if (!is_num(av[i]))
		{
			write(2, "Error\n", 6);
			free_and_exit(stck);
		}
		num = ft_atol(av[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			write(2, "Error\n", 6);
			free_and_exit(stck);
		}
		if (is_duplicate(av, num))
		{
			write(2, "Error\n", 6);
			free_and_exit(stck);
		}
		append_node(stck, (int)num);
		i++;
	}
}

void	append_node(t_stack **stck, int value)
{
	t_stack	*node;

	if (!stck)
		return ;
	node = malloc(sizeof(t_stack));
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

int	is_ascending(t_stack *stck)
{
	t_stack	*head;

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

void	pop_node(t_stack **stck)
{
	t_stack	*node;
	t_stack	*last;

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

t_stack	*get_cheapest(t_stack *a)
{
	t_stack	*a_head;

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
