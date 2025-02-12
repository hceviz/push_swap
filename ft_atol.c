/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:40:00 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/12 05:14:46 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
