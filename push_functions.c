/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:36:18 by renatanaesi       #+#    #+#             */
/*   Updated: 2024/09/27 14:51:17 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_top(t_stack **src, t_stack **dest)
{
    t_node *temp;
    if ((*src)->top != NULL)
    {
        temp = (*src)->top;
        (*src)->top = (*src)->top->next;
        temp->next = (*dest)->top;
        (*dest)->top = temp;
        (*dest)->size++;
        (*src)->size--;
    }
}
void    pa(t_stack **a, t_stack **b)
{
    push_top(b, a);
    ft_printf("pa\n");
}
void    pb(t_stack **a, t_stack **b)
{
    push_top(a, b);
    ft_printf("pb\n");
}
int append(t_stack *stack, int value)
{
    t_node *new_node;
    t_node *current;

    new_node = create_node(value);
    if (!new_node)
        return 0;
    if (stack->top == NULL)
    {
        stack->top = new_node;
    }
    else
    {
        current = stack->top;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
    stack->size++;
    return 1;
}
