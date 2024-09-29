/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:27:44 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/29 11:05:07 by renatanaesi      ###   ########.fr       */
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
	b = create_stack();
	if (b == NULL)
	{
		free_stack(a);
		return (1);
	}
	manage_stacks(&a, &b);
}

void	manage_stacks(t_stack **a, t_stack **b)
{
	if (is_sorted_asc(*a))
	{
		free_stack(*b);
		free_stack(*a);
		return ;
	}
	if (get_stack_size(*a) <= 3)
	{
		manage_small_stack(a);
		free_stack(*b);
		free_stack(*a);
		return ;
	}
	fill_target_position(a);
	manage_big_stack(a, b);
	return ;
}

void	print_stack(t_stack *stack)
{
	t_node	*current;

	if (stack == NULL)
	{
		printf("stack is NULL\n");
		return ;
	}
	current = stack->top;
	while (current != NULL)
	{
		printf ("%d\n",current->value);
		current = current->next;
	}
}
