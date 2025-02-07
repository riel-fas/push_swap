/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_first_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 23:25:40 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/07 23:50:17 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_first_2(t_stack_node **a, t_stack_node **b)
{
	pb(a, b); //we push the first node
	pb(a, b); //we push the second one

	//make sure the first 2 nodes are sorted
	if ((*b)->nbr > (*b)->next->nbr)
		sa_sb(b);
}
