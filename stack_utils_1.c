/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 03:24:15 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/17 13:23:34 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_to_stack_A(t_stack_node **stack, int nb)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = nb;
 	if (!*stack) //if stack a is empty
	{
		*stack = node;
		node->prev = NULL;
	}
	else //if theres already nbrs in the stack a its finds the last node then set prev to it and next to null
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
//my version
// void populate_stack_A(t_stack_node **a, char **av)
// {
//     long nb;
//     int x = 0;

//     while (av[x])
//     {
//         nb = atoi_v2(av[x]);
//         if (nb > INT_MAX || nb < INT_MIN) // Check for integer overflow
//         {
//             free_stack(a);
//             error_exit();
//         }
//         append_to_stack_A(a, (int)nb);
//         x++;
//     }
// }
///////////////////////////

void populate_stack_A(t_stack_node **a, char **av, int start_index)
{
    long nb;
    int x = start_index;

    while (av[x])
    {
        nb = atoi_v2(av[x]);
        if (nb > INT_MAX || nb < INT_MIN) // Check for integer overflow
        {
            free_stack(a);
            error_exit();
        }
        append_to_stack_A(a, (int)nb);
        x++;
    }

    // After populating, check for duplicates
    check_duplicates(*a);
}


void check_duplicates(t_stack_node *stack)
{
    t_stack_node *current;
    t_stack_node *runner;

    current = stack;
    while (current)
    {
        runner = current->next;
        while (runner)
        {
            if (current->nbr == runner->nbr)
                error_exit();
            runner = runner->next;
        }
        current = current->next;
    }
}

