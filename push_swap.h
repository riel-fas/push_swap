/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 05:34:58 by riel-fas          #+#    #+#             */
/*   Updated: 2025/02/01 05:55:28 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP.H
# define PUSH_SWAP.H



#include <stdbool.h>
#include <limits.h>
#include
#include





typedef struct s_stack_node
{

	int 					nbr;
	int 					index;
	int 					push_cost;
	bool					abo_med;
	bool					cheap;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
	struct s_stack_node		*targeted_node;
}	t_stack_node













#endif
