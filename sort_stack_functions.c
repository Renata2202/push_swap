/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:46:18 by renatanaesi       #+#    #+#             */
/*   Updated: 2024/09/16 10:21:25 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void manage_smal_stack(t_stack *stack)
{
if (stack == NULL || stack->top == NULL)
    {
        return;
    }
if (is_sorted_asc(stack) == true)
    {
        return;
    }
else if (get_stack_size(stack) == 1)
    {
        return;
    }
 else if (get_stack_size(stack) == 2)
    {
        if (stack->top->value > stack->top->next->value)
            sa(stack);
        return;
    }
else if (get_stack_size(stack) == 3)
    {
        sort_three_asc(stack);
        return;
    }
}

void sort_three_asc(t_stack *stack)
{
    t_node *first = stack->top;
    t_node *second = first->next;
    t_node *third = second->next;

    if (stack == NULL || stack->top == NULL || stack->top->next == NULL || stack->top->next->next == NULL)
    {
        return;
    }
    //132
    if (first->value < second->value && first->value < third->value && second->value > third->value)
    {
        sa(stack);
        ra(stack);
    }
    //231
    else if (first->value < second->value && first->value > third->value && second->value > third->value)
    {
        rra(stack);
    }
   // 213
    else if (first->value > second->value && first->value < third->value && second->value < third->value)
    {
        sa(stack);
    }
    //321
    else if (first->value > second->value && first->value > third->value && second->value > third->value)
    {
        sa(stack);
        rra(stack);
    }
    //312
    else if (first->value > second->value && first->value > third->value && second->value < third->value)
    {
            ra(stack);
    }
    return;
}
bool    is_sorted_asc(t_stack *stack)
{
    t_node *current = stack->top;
    while (current != NULL && current->next != NULL)
    {
        if (current->value > current->next->value)
        {
            ft_printf("Stack is not sorted crescent\n");
            return false;
        }
        current = current->next;
    }
    ft_printf("Stack is sorted crescent\n");
    return true;
}

