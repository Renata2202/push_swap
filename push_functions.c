/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:27:08 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/30 17:13:28 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(t_stack **src, t_stack **dest)
{
	t_node	*temp;

	if ((*src)->top != NULL)
	{
		temp = (*src)->top;
		(*src)->top = (*src)->top->next;
		temp->next = (*dest)->top;
		(*dest)->top = temp;
		(*dest)->size++;
		(*src)->size--;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push_top(b, a);
	write (1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push_top(a, b);
	write (1, "pb\n", 3);
}

int	append(t_stack *stack, int val)
{
	t_node	*new_node;
	t_node	*current;

	new_node = create_node(val);
	if (!new_node)
		return (0);
	if (stack->top == NULL)
	{
		stack->top = new_node;
	}
	else
	{
		current = stack->top;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
	stack->size++;
	return (1);
}
