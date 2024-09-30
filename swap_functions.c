/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:23:15 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/30 17:13:10 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_two(t_stack **stack)
{
	t_node	*first;
	t_node	*second;

	if ((*stack)->top != NULL && (*stack)->top->next != NULL)
	{
		first = (*stack)->top;
		second = (*stack)->top->next;
		first->next = second->next;
		second->next = first;
		(*stack)->top = second;
	}
}

void	sa(t_stack **a)
{
	swap_top_two(a);
	write (1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap_top_two(b);
	write (1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_top_two(a);
	swap_top_two(b);
	write (1, "ss\n", 3);
}
