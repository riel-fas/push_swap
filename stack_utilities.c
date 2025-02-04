/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 03:25:37 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/02 03:25:50 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack_node *stack) //Define a function that checks if the stack is sorted in ascending order
{
	if (!stack)
		return (1);
	while (stack->next) //Loop until the end of the stack is reached
	{
		if (stack->nbr > stack->next->nbr) //Check if the current value is larger than the next node's value, indicating it is out of sort
			return (false);
		stack = stack->next; //If not, move to the next node for processing
	}
	return (true);
}
