/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 04:28:16 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/16 01:24:23 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool stack_sort_check(t_stack_node *stack)
{
    if (!stack || !stack->next)
        return true; // Empty or single-node stack is sorted
    while (stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return false;
        stack = stack->next;
    }
    return true;
}

int stack_length(t_stack_node *stack)
{
    int x = 0;
    while (stack)
    {
        x++;
        stack = stack->next;
    }
    return x;
}


// int	stack_length(t_stack_node *stack)
// {
// 	int x;

// 	x = 0;
// 	while (stack->next)
// 	{
// 		x++;
// 		stack = stack->next;
// 	}
// 	return (x);
// }

t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next) //Loop until the end of the stack is reached
		stack = stack->next;
	return (stack);
}
