/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 04:43:18 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/17 19:10:55 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sort the 3 nodes left
void sort_three(t_stack_node **a)
{
	if (!a || !*a || !(*a)->next || !(*a)->next->next) // Ensure stack A has exactly 3 nodes
		return;
	if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
		ra_rb(a, 'a');
	else if ((*a)->next->nbr > (*a)->nbr && (*a)->next->nbr > (*a)->next->next->nbr)
		rra_rrb(a, 'a');
	if ((*a)->nbr > (*a)->next->nbr)
		sa_sb(a, 'a');
}

void move_to_top(t_stack_node **stack, t_stack_node *target)
{
	bool			found;
	int				moves_up;
	t_stack_node	*temp;
	int				stack_size;
	int				moves_down;


	if (!stack || !*stack || !target)
		return;
    // Check if target is already at the top
	if (*stack == target)
		return;
    // First, verify the target is actually in the stack
	temp = *stack;
	found = false;
	while (temp)
	{
		if (temp == target)
		{
			found = true;
			break;
		}
		temp = temp->next;
	}
	if (!found)
		return;  // Target not in stack
    // Now safely calculate moves
	moves_up = 0;
	temp = *stack;
	while (temp && temp != target)
	{
		moves_up++;
		temp = temp->next;
	}
	stack_size = stack_length(*stack);
	moves_down = stack_size - moves_up;
    // Move in the most efficient direction
	if (moves_up <= moves_down)
	{
		int  i = 0;
		while (i < moves_up)
		{
			ra_rb(stack, '\0');
			i++;
		}
	}
	else
	{
		int i = 0;
		while (i < moves_down)
		{
			rra_rrb(stack, '\0');
			i++;
		}
	}
}

int get_position(t_stack_node *node)
{
	int cost = 0;
	t_stack_node *tmp;

	if (!node)
		return (INT_MAX); // Return maximum cost if node is NULL
	tmp = node;
	while (tmp && tmp->prev)
	{
		cost++;
		tmp = tmp->prev;
	}
	return (cost);
}

t_stack_node *find_best_insert_position(t_stack_node *a, int nbr)
{
    t_stack_node *current;
    t_stack_node *best_pos;
    t_stack_node *smallest;

	current = a;
	best_pos = NULL;
    // If stack A is empty, return NULL
	if (!current)
		return NULL;
    // Find the smallest element in stack A
	smallest = find_min(a);
    // If the number to insert is smaller than the smallest in A,
    // return the smallest as the position (we'll rotate to it)
	if (nbr < smallest->nbr)
		return smallest;
    // Otherwise, find the position where nbr should be inserted
	while (current)
	{
		if (current->nbr > nbr &&
			(current->prev == NULL || current->prev->nbr < nbr))
		{
			best_pos = current;
			break;
		}
		current = current->next;
	}
    // If no position found (nbr is larger than all elements),
    // return the smallest element so we can rotate to put the largest at the end
	if (!best_pos)
		return smallest;
	return best_pos;
}

void push_back_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *target;

	while (*b)
	{
		if (*a)
		{
			target = find_best_insert_position(*a, (*b)->nbr);
			if (target) // If a position was found
				move_to_top(a, target);
		}
		pa(a, b); // Push from B to A
	}
}
