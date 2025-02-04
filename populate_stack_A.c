/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 03:24:15 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/03 14:10:47 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static long	atoi_v2(char *av)
{
	int		sign ;
	int		x;
	long	result;

	x = 0;
	sign = 1;
	result = 1;
	while ((av[x] >= 9 && av[x] <= 13) || av[x] == 32)
		x++;
	if (av[x] == '+' || av[x] == '-')
	{
		if (av[x] == '-')
			sign = -1;
		x++;
	}
	while (av[x] >= 48 && av[x] <= 57)
	{
		result = result * 10 + (av[x] - 48);
		x++;
	}
	return (result * sign);
}
static void	append_to_stack(t_stack_node **stack, int nb)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	// if (!stack)
	// {


	// }
	node = maloc(sizeof(t_stack_node));
	if (!node)
	{
		return ;
	}
	node->next = NULL;
	node->nbr = nb;
 	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(stack);
		last_node->next = node;
		node->next = last_node;
	}
}

//Define a function that returns the pointer to the last node
static t_stack_node	*find_last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next) //Loop until the end of the stack is reached
		stack = stack->next;
	return (stack);
}

void	populate_stack_A(char **av, t_stack_node a)
{
	long nb;
	int x;

	while (av[x])
	{
		nb = atoi_v2(av[x]);
		x++;
	}
	append_to_node(a, (int)nb);
}


