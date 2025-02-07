/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 02:55:09 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/07 18:59:06 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rrb(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*second_last;
	// if (!stack || !*stack || !(*stack)->next)
		// return;
	last = *stack;
	while (last->next) // Find the last node
		last = last->next;
	second_last = last->prev; // Get the second last node
	second_last->next = NULL; // Detach last node
	last->prev = NULL;
	last->next = *stack; // Move last to the top
	(*stack)->prev = last;
	*stack = last; // Update head
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rra_rrb(a);
	rra_rrb(b);
}

