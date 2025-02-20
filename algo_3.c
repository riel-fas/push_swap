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

void final_adjustments(t_stack_node **a)
{
    t_stack_node *min_node;

	min_node = find_min(*a);
    move_to_top(a, min_node);
}

void sort_stack_b(t_stack_node **b)
{
	int len;
	t_stack_node *largest;
	t_stack_node *current;

	if (!b || !*b || !(*b)->next)
		return;

	len = stack_length(*b);
    // For just 2 elements, a simple swap if needed
	if (len == 2)
	{
		if ((*b)->nbr < (*b)->next->nbr)
			sa_sb(b, 'b');
		return;
	}
    // For more elements, we want to keep the largest at the top of B
	largest = *b;
	current = *b;
	while (current)
	{
		if (current->nbr > largest->nbr)
			largest = current;
		current = current->next;
	}
    // Move the largest to the top
	move_to_top(b, largest);
    // Optionally, you could recursively sort the rest of the stack
    // But since we'll be pushing elements back one by one, this is often enough
}

void push_nodes_to_b(t_stack_node **a, t_stack_node **b)
{
	int count;
	int max_iterations; // Safety to prevent infinite loops

	max_iterations = 10000;
	count = 0;
	while (stack_length(*a) > 3 && count < max_iterations)
	{
		t_stack_node *best_node = find_cheapest_node(*a, *b);
		if (!best_node) // Exit if no valid node found
			break;
		move_to_top(a, best_node); // Bring best node to top
		pb(a, b);
		count++;
	}
	if (count >= max_iterations)
		write(2, "Warning: Maximum iterations reached in push_nodes_to_b\n", 54);
}
