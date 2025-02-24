/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hceviz <hceviz@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:59:53 by hceviz            #+#    #+#             */
/*   Updated: 2025/02/24 09:57:18 by hceviz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost;
	bool			a_median;
	bool			is_cheapest;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

//a_to_b.c
t_stack	*find_closest_smaller(t_stack *b, int a_value);
void	set_target_for_a(t_stack *a, t_stack *b);
void	calculate_cost(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *a);
void	tune_nodes_a(t_stack *a, t_stack *b);

//b_to_a.c
t_stack	*find_closest_bigger(t_stack *a, int b_value);
void	set_target_for_b(t_stack *a, t_stack *b);
void	tune_nodes_b(t_stack *a, t_stack *b);

//check.c
int		ft_isdigit(int c);
int		is_num(char *num);
int		is_duplicate(char **av, long num);
void	free_stack(t_stack **stck);
void	free_and_exit(t_stack **stck);

//megasort.c
void	megasort(t_stack **a, t_stack **b);
void	prep_push(t_stack **stck, t_stack *node_for_top, char t_stack_name);
void	revnormal_both(t_stack **a, t_stack **b, t_stack *chpst, char r_type);

//push.c
void	pa(t_stack **b, t_stack **a, bool print);
void	pb(t_stack **a, t_stack **b, bool print);

//rotate.c
void	r_both_ways(t_stack **stck, char drcton, char t_stcknme, bool prnt);
void	rr(t_stack **a, t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);

//split.c
char	**split(char *s, char c);

//stack_helper.c
void	minisort(t_stack **stck);
void	update_index(t_stack *stck);
void	top_min(t_stack **a);

//stack.c
void	stack_init(t_stack **stck, char **av);
int		is_ascending(t_stack *stck);
t_stack	*get_cheapest(t_stack	*a);
void	append_node(t_stack **stck, int value);

//swap.c
void	sa(t_stack	**a, bool print);
void	sb(t_stack	**b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);

//utils.c
void	ft_putstr(char *str);
long	ft_atol(const char *p);
int		stacklen(t_stack *stck);
t_stack	*getmax(t_stack *stck);
t_stack	*getmin(t_stack *stck);

#endif
