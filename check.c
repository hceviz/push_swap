/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:55:00 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/21 11:36:30 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_num(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(char **av, long num)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (av[i])
	{
		if (ft_atol(av[i]) == num)
			count++;
		i++;
	}
	if (count > 1)
		return (1);
	return (0);
}

void	free_stack(Stack **stck)
{
	Stack	*temp;
	Stack	*current;	

	if (!stck || !(*stck))
		return ;
	current = *stck;
	(*stck)->prev->next = NULL;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stck = NULL;
}

void	free_and_exit(Stack **stck)
{
	free_stack(stck);
	exit(EXIT_FAILURE);
}
