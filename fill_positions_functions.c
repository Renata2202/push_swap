/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_positions_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:11:30 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/30 15:49:29 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_positions(t_stack **a, t_stack **b)
{
	t_node	*current;
	int		position;

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

void	fill_target_position(t_stack **stack)
{
	t_node	*iter_node;
	t_node	*max_node;
	int		biggest;
	int		temp_pos;

	temp_pos = get_stack_size(*stack);
	while (temp_pos > 0)
	{
		iter_node = (*stack)->top;
		biggest = INT_MIN;
		max_node = NULL;
		while (iter_node)
		{
			if (iter_node->val > biggest && iter_node->trg_pos == 0)
			{
				biggest = iter_node->val;
				max_node = iter_node;
			}
			iter_node = iter_node->next;
		}
		if (max_node)
			max_node->trg_pos = temp_pos;
		temp_pos--;
	}
}

void	get_cost(t_stack **a, t_stack **b)
{
	t_node	*temp_b;
	int		size_a;
	int		size_b;

	temp_b = (*b)->top;
	size_a = get_stack_size(*a);
	size_b = get_stack_size(*b);
	fill_positions(a, b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->position;
		if (temp_b->position > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->position) * -1;
		temp_b->a_goal_pos = get_trg_a(a, temp_b->trg_pos, temp_b->a_goal_pos);
		temp_b->cost_a = temp_b->a_goal_pos;
		if (temp_b->a_goal_pos > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->a_goal_pos) * -1;
		temp_b = temp_b->next;
	}
}

int	get_min_position(t_stack *stack)
{
	t_node	*current;
	int		min_value;
	int		min_pos;
	int		pos;

	current = stack->top;
	min_value = current->val;
	min_pos = 0;
	pos = 0;
	while (current != NULL)
	{
		if (current->val < min_value)
		{
			min_value = current->val;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}
