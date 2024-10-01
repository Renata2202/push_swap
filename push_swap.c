/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:27:44 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/10/01 12:06:36 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = initialize_stack(argc, argv);
	if (a == NULL)
		return (1);
	create_stack(&b);
	if (b == NULL)
	{
		free_stack(a);
		return (1);
	}
	manage_stacks(&a, &b);
	print_stack(a);
	print_stack(b);
	free_stack(a);
	//print_stack(a);
}

void	manage_stacks(t_stack **a, t_stack **b)
{
	if (is_sorted_asc(*a))
	{
		free_stack(*b);
		return ;
	}
	if (get_stack_size(*a) <= 3)
	{
		manage_small_stack(a);
		free_stack(*b);
		return ;
	}
	fill_target_position(a);
	manage_big_stack(a, b);
	free_stack(*b);
	return ;
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->top;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
int	get_stack_size(t_stack *stack)
{
	int		size;
	t_node	*current;

	size = 0;
	current = stack->top;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL)
	{
		printf("stack is NULL\n");
		return ;
	}
	printf("stack: %p\n", stack);
	current = stack->top;
	while (current != NULL)
	{
		printf ("value: %d\t, curr_pos: %d\t, targ_pod: \t%d\n", current->val, current->position, current->trg_pos);
		current = current->next;
	}
}
