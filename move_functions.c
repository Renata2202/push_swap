/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:26:01 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/29 12:54:13 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_values_to_b(t_stack **a, t_stack **b)
{
	int		size_a;
	int		size_b;

	size_a = get_stack_size(*a);
	size_b = 0;
	while (size_a > 3 && size_b < size_a / 2)
	{
		if ((*a)->top->target_pos <= size_a / 2)
		{
			pb(a, b);
			size_a--;
			size_b++;
		}
		else
			ra(a);
	}
	while (size_a > 3)
	{
		pb(a, b);
		size_a--;
	}
	manage_small_stack(a);
}

void	get_value_position(t_stack **stack)
{
	t_node	*aux;
	t_node	*highest;
	int		biggest;

	if (stack == NULL || *stack == NULL)
	{
		write (2, "Error\n", 6);
		return ;
	}
	aux = (*stack)->top;
	while (aux != NULL)
	{
		highest = aux;
		biggest = aux->val;
		while (highest != NULL)
		{
			if (highest->val > biggest)
				biggest = highest->val;
			highest = highest->next;
		}
		aux->position = biggest;
		aux = aux->next;
	}
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_node	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	cost_a = 0;
	cost_b = 0;
	tmp = (*stack_b)->top;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (absolute_value(tmp->cost_a) + absolute_value(tmp->cost_b) < cheapest)
		{
			cheapest = absolute_value(tmp->cost_b) + absolute_value(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	rotate_single(stack_a, stack_b, cost_a, cost_b);
	pa(stack_a, stack_b);
}

void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	if (*cost_a < 0 && *cost_b < 0)
	{
		while (*cost_a < 0 && *cost_b < 0)
		{
			rrr(a, b);
			(*cost_a)++;
			(*cost_b)++;
		}
	}
	else if (*cost_a > 0 && *cost_b > 0)
	{
		while (*cost_a > 0 && *cost_b > 0)
		{
			rr(a, b);
			(*cost_a)--;
			(*cost_b)--;
		}
	}
}

void	rotate_single(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
}
