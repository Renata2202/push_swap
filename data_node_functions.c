/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_node_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:23:53 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/28 19:03:32 by rnunes-a         ###   ########.fr       */
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
    return (size);
}

void    start_b(t_stack **a, t_stack **b)
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
