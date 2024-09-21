/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:36:18 by renatanaesi       #+#    #+#             */
/*   Updated: 2024/09/15 16:15:43 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_top(t_stack *src, t_stack *dest)
{
    if (src->top != NULL)
    {
        t_node *temp = src->top;
        src->top = src->top->next;
        temp->next = dest->top;
        dest->top = temp;
        dest->size++;
        src->size--;
        //fill_positions(src);
        //fill_positions(dest);
    }
}
void    pa(t_stack *a, t_stack *b)
{
    push_top(b, a);
}
void    pb(t_stack *a, t_stack *b)
{
    push_top(a, b);
}
int append(t_stack *stack, int value)
{
    t_node *new_node;

    new_node = create_node(value);
    if (!new_node)
        return 0;
    if (stack->top == NULL)
        stack->top = new_node;
    else
    {
        t_node *current = stack->top;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    stack->size++;
    return 1;
}

