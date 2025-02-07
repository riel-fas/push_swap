/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 00:27:32 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/07 00:50:23 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_stack_node *stack)
{
	int x;

	x = 0;
	while (stack->next)
	{
		x++;
		stack = stack->next
	}
	return (x);
}
