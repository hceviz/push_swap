/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:59:53 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/08 19:42:17 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	//int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
} Stack;

void	add_to_list(Stack **head, int value);
Stack	*create_node(int value);
#endif
