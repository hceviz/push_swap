/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:59:53 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/15 15:40:01 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost;
	//bool			a_median;
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
char **split(char *s, char c);
static char	*get_next_word(char *str, char separator);
static int	count_words(char *str, char separator);
int	ft_isdigit(int c);
int	is_sorted(Stack *stck);
int	stacklen(Stack **stck);
void	minisort(Stack **stck);
Stack	*getmax(Stack **stck);
Stack	*getmin(Stack **stck);
void	swap(Stack **stck);
void	sa(Stack	**a, bool print);
void	sb(Stack	**b, bool print);
void	ss(Stack **a, Stack **b, bool print);
Stack	*getlast(Stack **stck);
void	rotate(Stack **stck);
void	ra(Stack **a, bool print);
void	rb(Stack **b, bool print);
void	rr(Stack **a, Stack **b, bool print);
#endif
