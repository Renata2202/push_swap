/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:21:31 by renatanaesi       #+#    #+#             */
/*   Updated: 2024/09/14 22:04:20 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_top_two(t_stack *stack)
{
    if (stack->top != NULL && stack->top->next != NULL)
    {
        t_node *first;
        t_node *second;

        first = stack->top;
        second = stack->top->next;
        first->next = second->next;
        second->next = first;
        stack->top = second;
    }
}
void sa(t_stack *a)
{
    swap_top_two(a);
}
void sb(t_stack *b)
{
    swap_top_two(b);
}
void sab(t_stack *a, t_stack *b)
{
    swap_top_two(a);
    swap_top_two(b);
}
