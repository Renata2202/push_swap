/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:33:17 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/29 17:51:08 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_node	*first;
	t_node	*last;

	first = (*stack)->top;
	last = (*stack)->top;
	if (!stack || !(*stack)->top || !(*stack)->top->next)
		return ;
	while (last->next != NULL)
	{
		last = last->next;
	}
	(*stack)->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack **a)
{
	rotate(a);
	write (2, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write (2, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write (2, "rr\n", 3);
}
