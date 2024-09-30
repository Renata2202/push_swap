/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:44:20 by renatanaesi       #+#    #+#             */
/*   Updated: 2024/09/30 15:44:31 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_target_greater(t_stack **a, int b_targ_pos, int *a_goal_pos)
{
    t_node *tmp_a = (*a)->top;
    int target_position = INT_MAX;

    while (tmp_a)
    {
        if (tmp_a->trg_pos > b_targ_pos && tmp_a->trg_pos < target_position)
        {
            target_position = tmp_a->trg_pos;
            *a_goal_pos = tmp_a->position;
        }
        tmp_a = tmp_a->next;
    }
    return target_position;
}

int find_target_lesser(t_stack **a, int *a_goal_pos)
{
    t_node *tmp_a = (*a)->top;
    int target_position = INT_MAX;

    while (tmp_a)
    {
        if (tmp_a->trg_pos < target_position)
        {
            target_position = tmp_a->trg_pos;
            *a_goal_pos = tmp_a->position;
        }
        tmp_a = tmp_a->next;
    }
    return target_position;
}

int get_trg_a(t_stack **a, int b_targ_pos, int a_goal_pos)
{
    int target_position = find_target_greater(a, b_targ_pos, &a_goal_pos);
    if (target_position != INT_MAX)
        return a_goal_pos;

    return find_target_lesser(a, &a_goal_pos);
}
