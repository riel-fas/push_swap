/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 05:34:58 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/17 19:06:31 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

// Stack node structure definition
typedef struct s_stack_node
{
    int nbr;                // Value stored in the node
    struct s_stack_node *prev; // Pointer to the previous node
    struct s_stack_node *next; // Pointer to the next node
} t_stack_node;

// Function prototypes for push_swap operations
void push_first_2(t_stack_node **a, t_stack_node **b);
void push_swap(t_stack_node **a, t_stack_node **b);
void push_nodes_to_b(t_stack_node **a, t_stack_node **b);
void sort_three(t_stack_node **a);
void sort_stack_b(t_stack_node **b);
void push_back_to_a(t_stack_node **a, t_stack_node **b);
void final_adjustments(t_stack_node **a);



t_stack_node *find_max(t_stack_node *stack);
int find_median(t_stack_node *stack);
void check_duplicates(t_stack_node *stack);



// Stack utility functions
bool	stack_sort_check(t_stack_node *stack);

void populate_stack_A(t_stack_node **a, char **av, int start_index);
void free_stack(t_stack_node **stack);           // Free stack memory
void error_exit(void);                           // Handle errors
char **splitv2(char *s, char c);                 // Split string into array

// String parsing functions
long atoi_v2(char *av);                          // Custom atoi implementation

// Linked list utility functions
t_stack_node *find_last_node(t_stack_node *stack); // Find last node in the stack
int stack_length(t_stack_node *stack);             // Get the length of the stack

// Utility functions for checking positions and costs
int get_position_cost(t_stack_node *node);          // Get cost for positioning node in A
int get_insert_position_cost(t_stack_node *node, t_stack_node *b); // Get insertion cost for B

// Functions for performing operations on stacks with stack identification
void sa_sb(t_stack_node **stack, char id);  // Swap the top two elements of stack A or B
void ra_rb(t_stack_node **stack, char id);  // Rotate the stack (move top element to bottom)
void rra_rrb(t_stack_node **stack, char id); // Reverse rotate the stack (move bottom element to top)
void pa(t_stack_node **a, t_stack_node **b);  // Push element from stack B to stack A
void pb(t_stack_node **a, t_stack_node **b);  // Push element from stack A to stack B
void ss(t_stack_node **a, t_stack_node **b);  // Swap A and B
void rr(t_stack_node **a, t_stack_node **b);  // Rotate A and B
void rrr(t_stack_node **a, t_stack_node **b); // Reverse rotate A and B

// Other utility functions
t_stack_node *find_min(t_stack_node *stack);   // Find the minimum element in stack A
void move_to_top(t_stack_node **stack, t_stack_node *target, char stack_id); // Move node to the top of the stack
int get_position(t_stack_node *node);  // Get position of a node in the stack
t_stack_node *find_best_insert_position(t_stack_node *a, int value);  // Find best position to insert in stack B
t_stack_node *find_best_node_to_push(t_stack_node *a, t_stack_node *b);  // Find the best node to push from A to B
t_stack_node *find_cheapest_node(t_stack_node *a, t_stack_node *b);  // Find node with lowest cost

#endif
