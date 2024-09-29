/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:33:46 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/29 12:51:43 by renatanaesi      ###   ########.fr       */
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
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = (*stack)->top;
	second = first->next;
	third = second->next;
	if (first->val < second->val && first->val < third->val && second->val > third->val)
	{
		sa(stack);
		ra(stack);
	}
	else if (first->val < second->val && first->val > third->val && second->val > third->val)
		rra(stack);
	else if (first->val > second->val && first->val < third->val && second->val < third->val)
		sa(stack);
	else if (first->val > second->val && first->val > third->val && second->val > third->val)
	{
		sa(stack);
		rra(stack);
	}
	else if (first->val > second->val && first->val > third->val && second->val < third->val)
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
		if ((*stack_a)->top->target_pos > ((get_stack_size (*stack_a)) / 2))
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
