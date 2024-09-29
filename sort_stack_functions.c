/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:33:46 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/29 18:49:55 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manage_small_stack(t_stack **stack)
{
	int	size;

	if (is_sorted_asc(*stack))
		return ;
	size = get_stack_size(*stack);
	if (size == 2)
		sa(stack);
	else if (get_stack_size(*stack) == 3)
	{
		sort_three_asc(stack);
		return ;
	}
}

void	sort_three_asc(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->top->val;
	second = (*stack)->top->next->val;
	third = (*stack)->top->next->next->val;
	if (first < second && first < third && second > third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && first > third && second > third)
		rra(stack);
	else if (first > second && first < third && second < third)
		sa(stack);
	else if (first > second && first > third && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && first > third && second < third)
		ra(stack);
	return ;
}

bool	is_sorted_asc(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current != NULL && current->next != NULL)
	{
		if (current->val > current->next->val)
			return (false);
		current = current->next;
	}
	return (true);
}

void	manage_big_stack(t_stack **stack_a, t_stack **stack_b)
{
	send_values_to_b(stack_a, stack_b);
	while ((*stack_b)->top != NULL)
	{
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	while (!is_sorted_asc(*stack_a))
	{
		if ((*stack_a)->top->trg_pos > ((get_stack_size (*stack_a)) / 2))
			ra(stack_a);
		else
			rra(stack_a);
	}
}

int	process_stacks(t_stack *a, t_stack *b)
{
	if (get_stack_size(a) <= 3)
	{
		manage_small_stack(&a);
		free_stack(a);
		free_stack(b);
		return (0);
	}
	fill_target_position(&a);
	manage_big_stack(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
