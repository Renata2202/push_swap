/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_positions_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:11:30 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/28 18:25:14 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fill_positions(t_stack **a, t_stack **b)
{
    t_node *current;
    int position;

    current = (*a)->top;
    position = 0;
    while (current)
    {
        current->position = position;
        position++;
        current = current->next;
    }
    current = (*b)->top;
    position = 0;
    while (current)
    {
        current->position = position;
        position++;
        current = current->next;
    }
}
void fill_target_position(t_stack **stack)
{
    t_node *iter_node;
    t_node *max_node;
    int biggest;
    int temp_pos;

    temp_pos = get_stack_size(*stack);
    while (temp_pos > 0)
    {
        iter_node = (*stack)->top;
        biggest = INT_MIN;
        max_node = NULL;
        while (iter_node)
        {
            if (iter_node->value > biggest && iter_node->target_position == 0)
            {
                biggest = iter_node->value;
                max_node = iter_node;
            }
            iter_node = iter_node->next;
        }
        if (max_node)
            max_node->target_position = temp_pos;
        temp_pos--;
    }
}
void get_cost(t_stack **a, t_stack **b)
{
    t_node *temp_b;
    int size_a;
    int size_b;

    temp_b = (*b)->top;
    size_a = get_stack_size(*a);
    size_b = get_stack_size(*b);
    fill_positions(a, b);
    while (temp_b)
    {
        temp_b->cost_b = temp_b->position;
        if (temp_b->position > size_b / 2)
            temp_b->cost_b = (size_b - temp_b->position) * -1;
        temp_b->a_goal_position = get_target_in_a(a, temp_b->target_position, temp_b->a_goal_position);
        temp_b->cost_a = temp_b->a_goal_position;
        if (temp_b->a_goal_position > size_a / 2)
            temp_b->cost_a = (size_a - temp_b->a_goal_position) * -1;
        temp_b = temp_b->next;
    }
}
int get_target_in_a(t_stack **a, int b_targ_pos, int a_goal_position)
{
    t_node *tmp_a;
    int target_position = INT_MAX;

    tmp_a = (*a)->top;
    while (tmp_a)
    {
        if (tmp_a->target_position > b_targ_pos && tmp_a->target_position < target_position)
        {
            target_position = tmp_a->target_position;
            a_goal_position = tmp_a->position;
        }
        tmp_a = tmp_a->next;
    }
    if (target_position != INT_MAX)
        return a_goal_position;
    tmp_a = (*a)->top;
    while (tmp_a)
    {
        if (tmp_a->target_position < target_position)
        {
            target_position = tmp_a->target_position;
            a_goal_position = tmp_a->position;
        }
        tmp_a = tmp_a->next;
    }
    return a_goal_position;
}
int get_min_position(t_stack *stack)
{
    t_node *current = stack->top;
    int min_value = current->value;
    int min_pos = 0;
    int pos = 0;

    while (current != NULL)
    {
        if (current->value < min_value)
        {
            min_value = current->value;
            min_pos = pos;
        }
        current = current->next;
        pos++;
    }
    return min_pos;
}
