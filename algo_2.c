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
    if (!a || !*a || !(*a)->next || !(*a)->next->next)
        return;

    t_stack_node *first = *a;
    t_stack_node *second = first->next;
    t_stack_node *third = second->next;

    if (first->nbr > second->nbr && second->nbr > third->nbr)
    {
        sa_sb(a, 'a');
        rra_rrb(a, 'a');
    }
    else if (first->nbr > second->nbr && second->nbr < third->nbr && first->nbr > third->nbr)
    {
        ra_rb(a, 'a');
    }
    else if (first->nbr > second->nbr && second->nbr < third->nbr && first->nbr < third->nbr)
    {
        sa_sb(a, 'a');
    }
    else if (first->nbr < second->nbr && second->nbr > third->nbr && first->nbr > third->nbr)
    {
        rra_rrb(a, 'a');
    }
    else if (first->nbr < second->nbr && second->nbr > third->nbr && first->nbr < third->nbr)
    {
        sa_sb(a, 'a');
        ra_rb(a, 'a');
    }
}

void move_to_top(t_stack_node **stack, t_stack_node *target, char stack_id)
{
    if (!stack || !*stack || !target)
        return;

    // Calculate the number of rotations needed to bring the target to the top
    int moves_up = 0;
    t_stack_node *temp = *stack;
    while (temp && temp != target)
    {
        moves_up++;
        temp = temp->next;
    }

    int stack_size = stack_length(*stack);
    int moves_down = stack_size - moves_up;

    // Rotate in the most efficient direction
    if (moves_up <= moves_down)
    {
        for (int i = 0; i < moves_up; i++)
            ra_rb(stack, stack_id); // Pass stack_id instead of '\0'
    }
    else
    {
        for (int i = 0; i < moves_down; i++)
            rra_rrb(stack, stack_id); // Pass stack_id instead of '\0'
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
    while (*b)
    {
        t_stack_node *target = find_best_insert_position(*a, (*b)->nbr);
        if (target)
            move_to_top(a, target, 'a');
        pa(a, b);
    }
}


int find_median(t_stack_node *stack)
{
    int *arr;
    int i = 0;
    int len = stack_length(stack);
    t_stack_node *current = stack;

    if (!stack)
        return 0;

    // Copy stack values into an array
    arr = malloc(sizeof(int) * len);
    if (!arr)
        return 0;

    while (current)
    {
        arr[i++] = current->nbr;
        current = current->next;
    }

    // Sort the array
    for (i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Find the median
    int median = arr[len / 2];
    free(arr);
    return median;
}
