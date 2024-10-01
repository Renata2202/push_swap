/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:44:20 by renatanaesi       #+#    #+#             */
/*   Updated: 2024/10/01 14:49:02 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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
*/
int	get_trg_a(t_stack **a, int b_targ_pos, int a_goal_pos)
{
	t_node	*tmp_a;
	int		target_position;

	tmp_a = (*a)->top;
	target_position = INT_MAX;
	while (tmp_a)
	{
		if (tmp_a->trg_pos > b_targ_pos && tmp_a->trg_pos < target_position)
		{
			target_position = tmp_a->trg_pos;
			a_goal_pos = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	if (target_position != INT_MAX)
		return (a_goal_pos);
	tmp_a = (*a)->top;
	while (tmp_a)
	{
		if (tmp_a->trg_pos < target_position)
		{
			target_position = tmp_a->trg_pos;
			a_goal_pos = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	return (a_goal_pos);
}
