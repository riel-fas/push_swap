/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 02:55:09 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/16 00:43:21 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

// void    rra_rrb(t_stack_node **stack)
// {
// 	t_stack_node	*last;
// 	t_stack_node	*second_last;

//     // First, add back the safety checks
// 	if (!stack || !*stack || !(*stack)->next)
// 		return;
//     // Find the last node
// 	last = *stack;
// 	while (last->next)
// 		last = last->next;
//     // Get the second last node
// 	second_last = last->prev;
//     // Update the links
// 	second_last->next = NULL;  // Make second_last the new last node
// 	last->prev = NULL;         // Clear previous link of old last node
// 	last->next = *stack;       // Point old last node to the first node
// 	(*stack)->prev = last;     // Update first node's prev pointer
// 	*stack = last;             // Make the old last node the new first node
// }

// void	rrr(t_stack_node **a, t_stack_node **b)
// {
// 	rra_rrb(a);
// 	rra_rrb(b);
// }

#include "push_swap.h"
#include <stdio.h> // Include for printf

void print_stacks(t_stack_node *stack, char stack_name)
{
    printf("%c: ", stack_name);
    while (stack)
    {
        printf("%d ", stack->nbr);
        stack = stack->next;
    }
    printf("\n");
}

void rra_rrb(t_stack_node **stack)
{
    t_stack_node *last;
    t_stack_node *second_last;

    // Safety checks
    if (!stack || !*stack || !(*stack)->next)
        return;

    // Find the last node
    last = *stack;
    while (last->next)
        last = last->next;

    // Get the second last node
    second_last = last->prev;

    // Update the links
    second_last->next = NULL;  // Make second_last the new last node
    last->prev = NULL;         // Clear previous link of old last node
    last->next = *stack;       // Point old last node to the first node
    (*stack)->prev = last;     // Update first node's prev pointer
    *stack = last;             // Make the old last node the new first node

    // Debug statement
    printf("Performed rra_rrb\n");
    print_stacks(*stack, 'A'); // Assuming this is for stack A
}

void rrr(t_stack_node **a, t_stack_node **b)
{
    rra_rrb(a);
    rra_rrb(b);

    // Debug statement
    printf("Performed rrr\n");
    print_stacks(*a, 'A');
    print_stacks(*b, 'B');
}
