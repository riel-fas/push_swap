/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 01:23:12 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/08 05:46:11 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	first = *stack; //the head
	second = first->next;
	//swapping next
	first -> next = second->next;
	second -> next = first;
	//swapping prev
	second -> prev = NULL;
	first -> prev = second;
	//if there is more than 2 nodes
	if (first->next)
		first -> next -> prev = first;
	*stack = second; //updating the head
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	sa_sb(a);
	sa_sb(b);
}

void	ra_rb(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	first = *stack;
	last = first; //tofind the last node
	while (last->next)
		last = last -> next;
	//make the last node the head of linked list
	*stack = first->next;
	(*stack) -> prev = NULL;  //as always prev in the first node is null
	//attach the first node to the end of linked list
	first -> next = NULL;
	last -> next = first;  //last here is the last node (after the loop finding the last node)
	first -> prev = last;
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	ra_rb(a);
	ra_rb(b);
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*top_b;

	// if (!b || !*b)  // Check if B is empty
		// return;
	top_b = *b;  // Get the top node of B
	*b = top_b->next; // Move B head to the next node
	if (*b)
		(*b)->prev = NULL;
	top_b->next = *a; // Attach B top node to A head
	if (*a)
		(*a)->prev = top_b;
	*a = top_b;  // Update A head
}

void pb(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *top_a;

    if (!a || !*a) // Check if stack A is empty
        return;

    top_a = *a; // Get the top node of A
    *a = top_a->next; // Move A head to the next node
    if (*a)
        (*a)->prev = NULL;

    top_a->next = *b; // Attach A top node to B head
    if (*b)
        (*b)->prev = top_a;

    *b = top_a; // Update B head
}
