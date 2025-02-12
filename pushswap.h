/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:59:53 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/12 08:50:20 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <limits.h>
# include <stdbool.h>

# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost;
	bool			a_median;
	bool			is_cheapest;
	struct s_stack	*prev;
	struct s_stack	*next;
} Stack;

void	add_to_list(Stack **head, int value);
int		is_num(char *num);
int	is_duplicate(char **av, long num);
void	free_stack(Stack **stck);
void	free_and_exit(Stack **stck);
long	ft_atol(const char *p);
Stack	*find_last_node(Stack **stck);
void	append_node(Stack **stck, int value);
void	print_list(Stack **stck);
void	stack_init(Stack **stck, char **av);
#endif
