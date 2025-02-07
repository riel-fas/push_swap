/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 06:12:01 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/07 23:22:00 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack_node *a; //stack A
	t_stack_node *b; //stack B

	a = NULL;
	b = NULL;
	if (ac < 2 || (ac >= 2 && !av[1][0])) //if ac !=2 or the string of numbers is empty
	{
		// print error using ft_printf;
		// return (error message);
	}
	if (ac == 2)
		splitv2(av[1], ' '); //we split the string of numbers
	populate_stack_A(&a, **av); //populate stack a with nbrs
	if (!stack_sort_check(a)) //if stack is not sorted
	{
		//we push numbers from a to b until a have only 3 nbrs
		//so we keep pushing until 3 is left,
		//while pushing we keep sorting in b : by
		//using the other 2 numbers that have been already pushed
		//we push to b by calculating wich number have the least amount of operations to be pushed
		//after that we sort nbrs in b
		// sort the 3 numbers in a
		//repopulate stack a
		//if a sort is needed we use opeartions

		
















	}
	//________________________________________________________________________//^finished + operations
	// {
	// 	if (stack_length(a) == 2)
	// 		sa(&a, false);
	// 	else if (stack_length(a) == 3)
	// 		sort_three(&a);
	// 	else
	// 		sort_stacks(&a);
	// }
	free_stacks(&a, &b);
}

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

