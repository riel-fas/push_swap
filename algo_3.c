/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 04:49:06 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/17 19:11:08 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *find_min(t_stack_node *stack)
{
    t_stack_node *min_node;
    t_stack_node *current;

	if (!stack)
		return (NULL);

	min_node = stack;
	current = stack;
	while (current)
	{
		if (current->nbr < min_node->nbr)
			min_node = current;
		current = current->next;
	}
	return (min_node);
}

t_stack_node *find_max(t_stack_node *stack)
{
    t_stack_node *max_node;
    t_stack_node *current;

    if (!stack)
        return NULL;

    max_node = stack;
    current = stack;
    while (current)
    {
        if (current->nbr > max_node->nbr)
            max_node = current;
        current = current->next;
    }
    return max_node;
}

void final_adjustments(t_stack_node **a)
{
    t_stack_node *min_node = find_min(*a);
    move_to_top(a, min_node, 'a');
}

void sort_stack_b(t_stack_node **b)
{
    if (!b || !*b || !(*b)->next)
        return;

    t_stack_node *largest = find_max(*b);

    // Move the largest element to the top of stack B
    move_to_top(b, largest, 'b');

    // Ensure the stack is sorted
    while ((*b)->next && (*b)->nbr < (*b)->next->nbr)
        ra_rb(b, 'b');
}

void push_nodes_to_b(t_stack_node **a, t_stack_node **b)
{
    // int median = find_median(*a); // Find the median value in stack A

    while (stack_length(*a) > 3)
    {
        t_stack_node *best_node = find_cheapest_node(*a, *b);

        if (!best_node)
            break;

        // Move the best node to the top of stack A
        move_to_top(a, best_node, 'a');

        // Push the node to stack B
        pb(a, b);

        // Sort stack B if necessary
        if ((*b)->next && (*b)->nbr < (*b)->next->nbr)
            sa_sb(b, 'b');
    }
}
