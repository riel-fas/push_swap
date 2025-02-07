/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 05:34:58 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/07 03:10:07 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>


typedef struct s_stack_node
{	int 					nbr;

	int 					push_cost;
	int 					index;
	bool					cheap;
	bool					abo_med;
	struct s_stack_node		*prev;
	struct s_stack_node		*next;

	struct s_stack_node		*targeted_node;
}	t_stack_node;


void	populate_stack_A(char **av, t_stack_node a);
char	**split(char *s, char c);
int		stack_length(t_stack_node *stack);
bool	stack_sort_check(t_stack_node *stack);

//operaions
void	sa_sb(t_stack_node **stack);
void	ss(t_stack_node **a, t_stack_node **b);
void	ra_rb(t_stack_node **stack);
void	rr(t_stack_node **a, t_stack_node **b);
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **a, t_stack_node **b);
void	rra_rrb(t_stack_node **stack);
void	rrr(t_stack_node **a, t_stack_node **b);

#endif
