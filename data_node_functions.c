/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_node_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 22:49:20 by renatanaesi       #+#    #+#             */
/*   Updated: 2024/09/25 13:04:30 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_stack_size(t_stack *stack)
{
    int size = 0;
    t_node *current = stack->top;
    while (current)
    {
        size++;
        current = current->next;
    }
    return size;
}
void start_b(t_stack **a, t_stack **b)
{
    int size_a;
    int size_b;

    size_a = get_stack_size(*a);
    size_b = 0;

    while (size_a > 3 && size_b < size_a / 2 && size_b <= 3)
    {
        if ((*a)->top->position <= size_a / 2)
        {
            pb(a, b);
            size_a--;
            size_b++;
        }
        else
        {
            ra(a);
        }
    }
}
