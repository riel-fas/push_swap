/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 04:40:24 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/08 05:45:49 by riel-fas         ###   ########.fr       */
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
        sa_sb(b);
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

//moves in A
int get_position_cost(t_stack_node *node)
{
	int cost = 0;
	t_stack_node *tmp = node;

	while (tmp)
	{
        cost++;
        tmp = tmp->prev;
    }
    return (cost);
}

//moves in B
int get_insert_position_cost(t_stack_node *node, t_stack_node *b)
{
    int cost = 0;
    t_stack_node *tmp = b;

    while (tmp)
    {
        if (tmp->nbr > node->nbr && tmp->next->nbr < node->nbr)
            break;
        cost++;
        tmp = tmp->next;
    }
    return (cost);
}

t_stack_node *find_cheapest_node(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *best_node = a;
    t_stack_node *current = a;
    int min_cost = get_position_cost(a) + get_insert_position_cost(a, b);

    while (current)
    {
        int cost = get_position_cost(current) + get_insert_position_cost(current, b);
        if (cost < min_cost)
        {
            min_cost = cost;
            best_node = current;
        }
        current = current->next;
    }
    return (best_node);
}
