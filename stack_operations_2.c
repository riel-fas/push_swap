/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 02:55:09 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/17 19:05:55 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	rra_rrb(t_stack_node **stack)
// {
// 	t_stack_node	*last;
// 	t_stack_node	*second_last;
// 	// if (!stack || !*stack || !(*stack)->next)
// 		// return;
// 	last = *stack;
// 	while (last->next) // Find the last node
// 		last = last->next;
// 	second_last = last->prev; // Get the second last node
// 	second_last->next = NULL; // Detach last node
// 	last->prev = NULL;
// 	last->next = *stack; // Move last to the top
// 	(*stack)->prev = last;
// 	*stack = last; // Update head
// }

// void	rrr(t_stack_node **a, t_stack_node **b)
// {
// 	rra_rrb(a);
// 	rra_rrb(b);
// }



void rra_rrb(t_stack_node **stack, char id)
{
    t_stack_node *last;
    t_stack_node *second_last;

    if (!stack || !*stack || !(*stack)->next)
        return;

    last = *stack;
    while (last->next)
        last = last->next;

    second_last = last->prev;
    second_last->next = NULL;
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;

    // Print the move
    if (id == 'a')
        write(1, "rra\n", 4);
    else if (id == 'b')
        write(1, "rrb\n", 4);
}

void rrr(t_stack_node **a, t_stack_node **b)
{
    rra_rrb(a, '\0'); // Reverse rotate A without printing
    rra_rrb(b, '\0'); // Reverse rotate B without printing
    write(1, "rrr\n", 4); // Print "rrr" for the combined operation
}
