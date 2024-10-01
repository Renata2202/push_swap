/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:44:20 by renatanaesi       #+#    #+#             */
/*   Updated: 2024/10/01 19:02:16 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_trg_a(t_stack **a, int b_targ_pos, int a_goal_pos, int *tp)
{
	t_node	*tmp_a;

	tmp_a = (*a)->top;
	*tp = INT_MAX;
	while (tmp_a)
	{
		if (tmp_a->trg_pos > b_targ_pos && tmp_a->trg_pos < *tp)
		{
			*tp = tmp_a->trg_pos;
			a_goal_pos = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	if (*tp == INT_MAX)
		tmp_a = (*a)->top;
	while (tmp_a)
	{
		if (tmp_a->trg_pos < *tp)
		{
			*tp = tmp_a->trg_pos;
			a_goal_pos = tmp_a->position;
		}
		tmp_a = tmp_a->next;
	}
	return (a_goal_pos);
}
