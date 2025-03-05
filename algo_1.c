/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 04:40:24 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/17 19:09:16 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_first_2(t_stack_node **a, t_stack_node **b)
{
	if (!a || !*a || !(*a)->next) // Ensure stack A has at least 2 nodes
		return;
	pb(a, b); // Push the first node
	pb(a, b); // Push the second node
    // Make sure the first 2 nodes in B are sorted
	if ((*b)->nbr > (*b)->next->nbr)
		sa_sb(b, 'b');
}

t_stack_node	*find_best_node_to_push(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;
	t_stack_node	*best_node;
	int				best_cost;
	int				cost;

	if (!a)
		return (NULL);
	current = a;
	best_node = NULL;
	best_cost = INT_MAX;
	while (current)
	{
		cost = get_position_cost(current) + get_insert_position_cost(current, b);
		if (cost < best_cost)
		{
			best_cost = cost;
			best_node = current;
		}
		current = current->next;
	}
	return (best_node);
}

int get_position_cost(t_stack_node *node)
{
    if (!node)
        return INT_MAX; // Return maximum cost if node is NULL

    int cost = 0;
    t_stack_node *tmp = node;

    while (tmp && tmp->prev)
    {
        cost++;
        tmp = tmp->prev;
    }
    return cost;
}

int get_insert_position_cost(t_stack_node *node, t_stack_node *b)
{
	int				cost;
	t_stack_node	*tmp;

	cost = 0;
	tmp = b;
	if (!node || !b)
		return 0; // Return 0 if either is NULL
    // Handle special case where node goes at the beginning
	if (node->nbr < b->nbr && (find_last_node(b)->nbr < node->nbr || find_last_node(b)->nbr > b->nbr))
		return 0;
	while (tmp)
	{
		if (tmp->nbr > node->nbr && ((tmp->next && tmp->next->nbr < node->nbr) || !tmp->next))
			break;
		cost++;
		tmp = tmp->next;
		if (!tmp && cost > 0)
		{
			tmp = b; // Wrap to beginning
			if (cost >= stack_length(b)) // Safety exit
				break;
		}
	}
	return cost;
}

t_stack_node *find_cheapest_node(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *best_node = NULL;
    int min_cost = INT_MAX;
    t_stack_node *current = a;

    while (current)
    {
        // Calculate the total cost to move this node to the correct position in B
        int cost = get_position_cost(current) + get_insert_position_cost(current, b);

        // Update the best node if this one has a lower cost
        if (cost < min_cost)
        {
            min_cost = cost;
            best_node = current;
        }

        current = current->next;
    }

    return best_node;
}
