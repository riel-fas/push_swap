/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 04:43:18 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/16 03:31:06 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sort the 3 nodes left
// void sort_three(t_stack_node **a)
// {
//     if (!a || !*a || !(*a)->next || !(*a)->next->next) // Ensure stack A has exactly 3 nodes
//         return;

//     if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
//         ra_rb(a);
//     else if ((*a)->next->nbr > (*a)->nbr && (*a)->next->nbr > (*a)->next->next->nbr)
//         rra_rrb(a);

//     if ((*a)->nbr > (*a)->next->nbr)
//         sa_sb(a);
// }

void sort_three(t_stack_node **a)
{
    if (!a || !*a || !(*a)->next || !(*a)->next->next) // Ensure stack A has exactly 3 nodes
        return;

    if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
        ra_rb(a);
    else if ((*a)->next->nbr > (*a)->nbr && (*a)->next->nbr > (*a)->next->next->nbr)
        rra_rrb(a);

    if ((*a)->nbr > (*a)->next->nbr)
        sa_sb(a);
}


// void move_to_top(t_stack_node **stack, t_stack_node *target)
// {
//     int moves_up = get_position(target); // Moves required using `ra`
//     int moves_down = stack_length(*stack) - moves_up; // Moves required using `rra`

//     if (moves_up <= moves_down) // If moving up is better
//     {
//         while (*stack != target)
//             ra_rb(stack);
//     }
//     else // If moving down is better
//     {
//         while (*stack != target)
//             rra_rrb(stack);
//     }
// }

void move_to_top(t_stack_node **stack, t_stack_node *target)
{
    if (!stack || !*stack || !target)
        return;

    int moves_up = get_position(target); // Moves required using `ra`
    int moves_down = stack_length(*stack) - moves_up; // Moves required using `rra`

    if (moves_up <= moves_down) // If moving up is better
    {
        while (*stack != target)
            ra_rb(stack);
    }
    else // If moving down is better
    {
        while (*stack != target)
            rra_rrb(stack);
    }
}







int get_position(t_stack_node *node)
{
    int index = 0;
    while (node->prev) // Traverse backwards to find the index
    {
        node = node->prev;
        index++;
    }
    return index;
}

// t_stack_node	*find_best_node_to_push(t_stack_node *a, t_stack_node *b)
// {
// 	t_stack_node	*current;
// 	t_stack_node	*best_node;
// 	int				best_cost;
// 	int				cost;

// 	if (!a)
// 		return (NULL);
// 	current = a;
// 	best_node = NULL;
// 	best_cost = INT_MAX;
// 	while (current)
// 	{
// 		cost = get_position_cost(current) + get_insert_position_cost(current, b);
// 		if (cost < best_cost)
// 		{
// 			best_cost = cost;
// 			best_node = current;
// 		}
// 		current = current->next;
// 	}
// 	return (best_node);
// }


// t_stack_node *find_best_insert_position(t_stack_node *a, int nbr)
// {
//     t_stack_node *current = a;
//     while (current)
//     {
//         if (current->nbr > nbr)
//             return current;
//         current = current->next;
//     }
//     return NULL; // Or some other appropriate return value.
// }

// void push_back_to_a(t_stack_node **a, t_stack_node **b)
// {
//     while (*b)
//     {
//         t_stack_node *target = find_best_insert_position(*a, (*b)->nbr);
//         move_to_top(a, target);
//         pa(a, b);
//     }
// }


t_stack_node *find_best_insert_position(t_stack_node *a, int nbr)
{
    t_stack_node *current = a;
    while (current)
    {
        if (current->nbr > nbr)
            return current;
        current = current->next;
    }
    return NULL; // If no position is found, insert at the end
}

void push_back_to_a(t_stack_node **a, t_stack_node **b)
{
    while (*b)
    {
        t_stack_node *target = find_best_insert_position(*a, (*b)->nbr);
        if (!target) // If no target is found, insert at the end
            target = find_last_node(*a);
        move_to_top(a, target);
        pa(a, b);
        printf("Pushed %d back to stack A\n", (*a)->nbr); // Debug statement
    }
}
