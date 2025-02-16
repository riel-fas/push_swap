/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 03:24:15 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/16 03:44:03 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// static void	append_to_stack_A(t_stack_node **stack, int nb)
// {
// 	t_stack_node	*node;
// 	t_stack_node	*last_node;

// 	if (!stack)
// 		return ;
// 	node = malloc(sizeof(t_stack_node));
// 	if (!node)
// 		return ;
// 	node->next = NULL;
// 	node->nbr = nb;
//  	if (!*stack) //if stack a is empty
// 	{
// 		*stack = node;
// 		node->prev = NULL;
// 	}
// 	else //if theres already nbrs in the stack a its finds the last node then set prev to it and next to null
// 	{
// 		last_node = find_last_node(*stack);
// 		last_node->next = node;
// 		node->prev = last_node;
// 	}
// }

// void populate_stack_A(t_stack_node **a, char **av)
// {
// 	long nb;
// 	int x;

// 	x = 0;
// 	while (av[x])
// 	{
// 		nb = atoi_v2(av[x]);
// 		if (nb > INT_MAX || nb < INT_MIN) // Check for integer overflow
// 		{
// 			free_stack(a);
// 			error_exit();
// 		}
// 		append_to_stack_A(a, (int)nb);
// 		x++;
// 	}
// }

void append_to_stack_A(t_stack_node **stack, int nb)
{
    t_stack_node *node;
    t_stack_node *last_node;

    if (!stack)
        return;
    node = malloc(sizeof(t_stack_node));
    if (!node)
        return;
    node->next = NULL;
    node->nbr = nb;
    if (!*stack) // if stack a is empty
    {
        *stack = node;
        node->prev = NULL;
    }
    else // if there's already nbrs in the stack a, it finds the last node then set prev to it and next to null
    {
        last_node = find_last_node(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
    printf("Added %d to stack A\n", nb); // Debug statement
}

// void populate_stack_A(t_stack_node **a, char **av)
// {
//     long nb;
//     int x;

//     x = 0;
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
//     printf("Finished populating stack A\n"); // Debug statement
// }


// void populate_stack_A(t_stack_node **a, char **args)
// {
//     int i = 0;
//     long num;
//     t_stack_node *new_node;

//     while (args[i])
//     {
//         num = atoi_v2(args[i]);
//         if (num < INT_MIN || num > INT_MAX) // Check for integer overflow
//             error_exit();
//         if (is_duplicate(*a, (int)num)) // Check for duplicates
//             error_exit();
//         new_node = create_node((int)num);
//         if (!new_node)
//             error_exit();
//         add_node_to_stack(a, new_node);
//         i++;
//     }
// }

// void populate_stack_A(t_stack_node **a, char **args)
// {
//     int i = 0;
//     long num;
//     t_stack_node *new_node;

//     while (args[i])
//     {
//         num = atoi_v2(args[i]);
//         if (num < INT_MIN || num > INT_MAX) // Check for integer overflow
//             error_exit();
//         if (is_duplicate(*a, (int)num)) // Check for duplicates
//         {
//             printf("Duplicate value found: %ld\n", num); // Debug statement
//             error_exit();
//         }
//         new_node = create_node((int)num);
//         if (!new_node)
//             error_exit();
//         add_node_to_stack(a, new_node);
//         i++;
//     }
// }

void populate_stack_A(t_stack_node **a, char **args)
{
    int i = 0;
    long num;
    t_stack_node *new_node;

    while (args[i])
    {
        num = atoi_v2(args[i]);
        if (num < INT_MIN || num > INT_MAX) // Check for integer overflow
            error_exit();

        printf("Checking for duplicate: %ld\n", num); // Debug statement

        if (is_duplicate(*a, (int)num)) // Check for duplicates
        {
            printf("Duplicate value found: %ld\n", num); // Debug statement
            error_exit();
        }

        new_node = create_node((int)num);
        if (!new_node)
            error_exit();

        printf("Adding %ld to stack A\n", num); // Debug statement

        add_node_to_stack(a, new_node);
        i++;
    }
}

void add_node_to_stack(t_stack_node **stack, t_stack_node *new_node)
{
    if (!stack || !new_node)  // Check for NULL pointers
        return;

    if (*stack)  // If the stack is not empty
    {
        new_node->next = *stack;  // Link the new node to the current top of the stack
        (*stack)->prev = new_node; // Link the current top back to the new node
    }

    *stack = new_node;  // Update the stack's head to point to the new node
}



bool is_duplicate(t_stack_node *stack, int num)
{
    printf("Checking stack for duplicate of %d:\n", num); // Debug statement
    while (stack)
    {
        printf("Stack node: %d\n", stack->nbr); // Debug statement
        if (stack->nbr == num)
            return true;
        stack = stack->next;
    }
    return false;
}

// #include "push_swap.h"  // Include the header file for the stack structure and function prototypes

t_stack_node *create_node(int nbr)
{
    t_stack_node *new_node;

    // Allocate memory for the new node
    new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
    if (!new_node)  // Check if malloc failed
        return (NULL);

    // Initialize the node's fields
    new_node->nbr = nbr;  // Set the node's value
    new_node->prev = NULL; // Initialize prev pointer to NULL
    new_node->next = NULL; // Initialize next pointer to NULL

    return (new_node);  // Return the newly created node
}
