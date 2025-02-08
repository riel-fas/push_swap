/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 04:49:06 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/08 05:28:42 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *find_min(t_stack_node *stack)
{
    if (!stack)
        return (NULL);

    t_stack_node *min_node = stack;
    t_stack_node *current = stack;

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
    t_stack_node *min_node = find_min(*a);
    move_to_top(a, min_node);
}

void sort_stack_b(t_stack_node **b)
{
    if ((*b)->nbr < (*b)->next->nbr)
        sa_sb(b);
}

void push_nodes_to_b(t_stack_node **a, t_stack_node **b)
{
    while (stack_length(*a) > 3)
    {
        t_stack_node *best_node = find_cheapest_node(*a, *b);
        move_to_top(a, best_node); // Bring best node to top
        pb(a, b);
    }
}





