/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 06:12:01 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/18 15:10:51 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void free_stack(t_stack_node **stack)
{
	t_stack_node *tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void free_args(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

// void push_swap(t_stack_node **a, t_stack_node **b)
// {
//     if (stack_sort_check(*a))
//         return;

//     push_first_2(a, b);
//     push_nodes_to_b(a, b);
//     sort_three(a);
//     sort_stack_b(b);
//     push_back_to_a(a, b);
//     final_adjustments(a);
// }
////////////////////////////////////////////////////////////////////


//
void print_stack(t_stack_node *stack, const char *name)
{
    printf("%s: ", name);
    while (stack)
    {
        printf("%d ", stack->nbr);
        stack = stack->next;
    }
    printf("\n");
}



//
void push_swap(t_stack_node **a, t_stack_node **b)
{
    if (stack_sort_check(*a))
    {
        printf("Stack is already sorted\n");
        return;
    }

    printf("Initial stack A:\n");
    print_stack(*a, "A");

    printf("Pushing first 2 elements to stack B\n");
    push_first_2(a, b);
    print_stack(*a, "A");
    print_stack(*b, "B");

    printf("Pushing nodes to stack B\n");
    push_nodes_to_b(a, b);
    print_stack(*a, "A");
    print_stack(*b, "B");

    printf("Sorting the last 3 elements in stack A\n");
    sort_three(a);
    print_stack(*a, "A");

    printf("Sorting stack B\n");
    sort_stack_b(b);
    print_stack(*b, "B");

    printf("Pushing elements back to stack A\n");
    push_back_to_a(a, b);
    print_stack(*a, "A");

    printf("Final adjustments\n");
    final_adjustments(a);
    print_stack(*a, "A");
}
////////////////////////////////////////////

// void push_swap(t_stack_node **a, t_stack_node **b)
// {
// 	if (stack_sort_check(*a))
// 	{
// 		return;
// 	}

// 	push_first_2(a, b);

// 	push_nodes_to_b(a, b);

// 	sort_three(a);

// 	sort_stack_b(b);

// 	push_back_to_a(a, b);

// 	final_adjustments(a);
// }




///////////////////////////
int main(int ac, char **av)
{
	t_stack_node	*a; // Stack A
	t_stack_node	*b; // Stack B
	char			**args;
	int				start_index; // Default starting index when av is not split

	start_index = 1;
	a = NULL;
	b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0])) // Check for valid input
		error_exit();
	if (ac == 2) // Single argument with space-separated numbers
	{
		args = splitv2(av[1], ' '); // Split numbers if single string is provided
		start_index = 0; // Start from index 0 when args is from split
	}
	else // Multiple command-line arguments
	{
		args = av;
		start_index = 1; // Skip program name (av[0])
	}
	populate_stack_A(&a, args, start_index);
	if (stack_sort_check(a)) // If already sorted, free memory and exit
	{
		free_stack(&a);
		if (ac == 2)
			free_args(args);
		return (0);
	}
	push_swap(&a, &b);
    // Free memory before exiting
	free_stack(&a);
	free_stack(&b);
	if (ac == 2)
		free_args(args);
		return (0);
}

////////////////////////



//1/ declaring 2 pointers for 2 linked lists for stacks A and B
	//set them both to null to avoid u.b
//2/ handling input errors // ac >= 2 // 2nd input must not be empty
	//if input error // return error message
//3/ handle both ways of the program input
	//if a string we should use split to split it into substrings
	//or the normale way
//4/ initialise A , appending input numbers each as a node to A
	//handle overflow, dups, or syntax error
		//if an error , free A and return error
	//check input , if its a long
		//if its a string convert to long int
	// appending nodes to A
//5/ check if A is  sorted
	//if not, sorting algo
		//check for 2 numbers
			// if so, swap the numbers
		//check for 3 numbers
			//if so, sort three algo
		// if stack has more than 3 numbers
			// if so , turk algo

// functions : handling errors ; operations ; stack length ; last node

/////////////////////////////////////////////////////////////////////////////////

// #include "push_swap.h"
// #include <stdio.h> // Include for printf

// void free_stack(t_stack_node **stack)
// {
//     t_stack_node *tmp;

//     while (*stack)
//     {
//         tmp = *stack;
//         *stack = (*stack)->next;
//         free(tmp);
//     }
// }

// void free_args(char **args)
// {
//     int i = 0;

//     while (args[i])
//     {
//         free(args[i]);
//         i++;
//     }
//     free(args);
// }

// void print_stack(t_stack_node *stack, const char *name)
// {
//     printf("%s: ", name);
//     while (stack)
//     {
//         printf("%d ", stack->nbr);
//         stack = stack->next;
//     }
//     printf("\n");
// }

// void push_swap(t_stack_node **a, t_stack_node **b)
// {
//     if (stack_sort_check(*a))
//         return;

//     push_first_2(a, b);
//     push_nodes_to_b(a, b);
//     sort_three(a);
//     sort_stack_b(b);
//     push_back_to_a(a, b);
//     final_adjustments(a);
// }

// int main(int ac, char **av)
// {
//     t_stack_node *a = NULL; // Stack A
//     t_stack_node *b = NULL; // Stack B
//     char **args;
//     int start_index = 1; // Default starting index when av is not split

//     if (ac < 2 || (ac == 2 && !av[1][0])) // Check for valid input
//     {
//         error_exit();
//     }

//     if (ac == 2) // Single argument with space-separated numbers
//     {
//         args = splitv2(av[1], ' '); // Split numbers if single string is provided
//         start_index = 0; // Start from index 0 when args is from split
//     }
//     else // Multiple command-line arguments
//     {
//         args = av;
//         start_index = 1; // Skip program name (av[0])
//     }

//     populate_stack_A(&a, args, start_index);
//     print_stack(a, "A");

//     if (stack_sort_check(a)) // If already sorted, free memory and exit
//     {
//         free_stack(&a);
//         if (ac == 2)
//             free_args(args);
//         return (0);
//     }

//     push_swap(&a, &b);

//     // Print stack A after sorting
//     print_stack(a, "A after sorting");

//     // Free memory before exiting
//     free_stack(&a);
//     free_stack(&b);
//     if (ac == 2)
//         free_args(args);

//     return (0);
// }
