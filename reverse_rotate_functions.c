/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:28:25 by renatanaesi       #+#    #+#             */
/*   Updated: 2024/09/16 09:11:41 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void reverse_rotate(t_stack *stack)
{
    if (!stack || !stack->top || !stack->top->next)
        return;

    t_node *prev = NULL;
    t_node *current = stack->top;

    while (current->next != NULL)
    {
        prev = current;
        current = current->next;
    }
    if (prev != NULL)
    {
        prev->next = NULL;
    }
    prev->next = NULL;
    current->next = stack->top;
    stack->top = current;

}
void rra(t_stack *a)
{
    reverse_rotate(a);
}
void rrb(t_stack *b)
{
    reverse_rotate(b);
}
void rrr(t_stack *a, t_stack *b)
{
    reverse_rotate(a);
    reverse_rotate(b);
}
