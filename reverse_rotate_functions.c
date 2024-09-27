/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:25 by renatanaesi       #+#    #+#             */
/*   Updated: 2024/09/27 14:53:06 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void reverse_rotate(t_stack **stack)
{
    t_node *prev;
    t_node *current;
    if (!(*stack) || !(*stack)->top || ! (*stack)->top->next)
        return;

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
void rra(t_stack **a)
{
    reverse_rotate(a);
    ft_printf("rra\n");
}
void rrb(t_stack **b)
{
    reverse_rotate(b);
    ft_printf("rrb\n");
}
void rrr(t_stack **a, t_stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    ft_printf("rrr/n");
}
