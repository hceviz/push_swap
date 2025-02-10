/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:54:07 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/08 16:44:07 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	is_duplicate(int num, char **av, int i) //or not static?
{
	i++;
	while (av[i])
	{
		if (ft_atol(av[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	is_num(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_args(int ac, char **av)
{
	char	**new_av;
	int		i;
	long	temp;

	i = 0;
	if (ac == 2)
		new_av = ft_split(av[1], ' ');
	else
	{
		i = 1;
		new_av = av;
	}
	/*while block has to work in every condition that is why i wrote seperately
	if we have ac = 2 but what if this one argument "11 22 33". it has to be checked.
	so this seperate while loop checks it even if it has ac = 2*/
	while (new_av[i])
	{
		temp = ft_atol(new_av[i]);
		if (!is_num(new_av[i]))
			//error
		if (is_duplicate(temp, new_av, i))
			//error
		if (temp < INT_MIN || temp > INT_MAX)
			//error
		i++;
	}
	if (ac == 2) //this is for freeing if we used split with ac = 2 cuz we dont need split when ac > 2
	{
		//free (new_av)
	}
}
