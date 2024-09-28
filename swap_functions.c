/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:23:15 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/28 21:16:55 by rnunes-a         ###   ########.fr       */
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
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap_top_two(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap_top_two(a);
	swap_top_two(b);
	ft_printf("ss\n");
}
