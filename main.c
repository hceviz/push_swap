/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:00:08 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/23 14:26:55 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		exit(1);
	if (ac == 2 && (!av[1] || av[1][0] == '\0'))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	else if (ac == 2)
		av = split(av[1], ' ');
	stack_init(&a, av + 1);
	if (!is_ascending(a))
	{
		if (stacklen(a) <= 3)
			minisort(&a);
		else
			megasort(&a, &b);
	}
	free_stack(&a);
	return (0);
}
