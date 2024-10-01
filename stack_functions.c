/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:22:16 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/10/01 19:51:37 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int val)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		write (2, "Error\n", 6);
		return (NULL);
	}
	new_node->val = val;
	new_node->position = 0;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->a_goal_pos = 0;
	new_node->trg_pos = 0;
	new_node->next = NULL;
	return (new_node);
}

void	create_stack(t_stack **stack)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		write (2, "Error\n", 6);
		return ;
	}
	(*stack)->top = NULL;
	(*stack)->last = NULL;
	(*stack)->size = 0;
}

int	check_input(t_stack *stack, char *arg, int *val)
{
	if (!is_valid_input(arg))
		return (0);
	*val = ft_atoi(arg);
	if (!is_in_int_range(arg))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (has_repeated_numbers(stack, *val))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	add_to_stack(t_stack *stack, char *arg)
{
	int		val;
	t_node	*new_node;

	if (!check_input(stack, arg, &val))
		return (0);
	new_node = create_node(val);
	if (new_node == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (stack->top == NULL)
	{
		stack->top = new_node;
		stack->last = new_node;
	}
	else
	{
		stack->last->next = new_node;
		stack->last = new_node;
	}
	stack->size++;
	return (1);
}

t_stack	*initialize_stack(int argc, char **argv)
{
	int		i;
	t_stack	*stack;

	i = 1;
	stack = NULL;
	create_stack(&stack);
	if ((argc < 2) || (!stack))
	{
		write (2, "Error\n", 6);
		return (NULL);
	}
	while (i < argc)
	{
		if (!add_to_stack(stack, argv[i]))
		{
			free_stack(stack);
			return (NULL);
		}
		i++;
	}
	return (stack);
}
