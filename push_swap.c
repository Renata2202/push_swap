/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:27:44 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/28 20:17:49 by rnunes-a         ###   ########.fr       */
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
	if (is_sorted_asc(a))
	{
		free_stack(b);
		free_stack(a);
		return (0);
	}
	if (get_stack_size(a) <= 3)
	{
		manage_small_stack(&a);
		free_stack(b);
		free_stack(a);
		return (0);
	}
	fill_target_position(&a);
	manage_big_stack(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
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
