/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:25:42 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/22 14:05:35 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

long	ft_atol(const char *p)
{
	int		sign;
	int		i;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (p[i] && (p[i] == ' ' || p[i] == '\t'
			|| p[i] == '\n' || p[i] == '\r'
			|| p[i] == '\v' || p[i] == '\f'))
		i++;
	if (p[i] == '+')
		i++;
	if (p[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (p[i] >= 48 && p[i] <= 57)
	{
		res = (res * 10) + (p[i] - '0');
		i++;
	}
	return (res * sign);
}

int	stacklen(t_stack *stck)
{
	t_stack	*head;
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

t_stack	*getmax(t_stack *stck)
{
	int			highest;
	t_stack		*highest_node;
	t_stack		*head;

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

t_stack	*getmin(t_stack *stck)
{
	int			lowest;
	t_stack		*lowest_node;
	t_stack		*head;

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
