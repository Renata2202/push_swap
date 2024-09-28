/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:33:17 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/28 18:33:27 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack **stack)
{
    t_node *first;
    t_node *last;

    first = (*stack)->top;
    last = (*stack)->top;
    if (!stack || !(*stack)->top || !(*stack)->top->next)
        return;
    while (last->next != NULL)
    {
        last = last->next;
    }
    (*stack)->top = first->next;
    first->next = NULL;
    last->next = first;
}
void ra(t_stack **a)
{
    rotate(a);
    ft_printf("ra\n");
}
void rb(t_stack **b)
{
    rotate(b);
    ft_printf("rb\n");
}
void rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    ft_printf("rr\n");
}
