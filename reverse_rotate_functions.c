/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:32:44 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/30 17:12:22 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_node	*prev;
	t_node	*current;

	prev = NULL;
	current = (*stack)->top;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	if (prev != NULL)
	{
		prev->next = NULL;
	}
	current->next = (*stack)->top;
	(*stack)->top = current;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write (1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write (1, "rrr\n", 4);
}
