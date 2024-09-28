/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:32:44 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/28 18:32:53 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_stack **stack)
{
    t_node *prev;
    t_node *current;

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
    ft_printf("rrr\n");
}
