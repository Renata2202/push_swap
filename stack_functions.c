/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:22:16 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/28 18:37:25 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node  *create_node(int value)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (new_node == NULL)
    {
         write (2, "Error\n", 6);
        return NULL;
    }
    new_node->value = value;
    new_node->position = 0;
    new_node->cost_a = 0;
    new_node->cost_b = 0;
    new_node->a_goal_position = 0;
    new_node->target_position = 0;
    new_node->next = NULL;
    return new_node;
}
t_stack *create_stack()
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (stack == NULL)
    {
        write (2, "Error\n", 6);
        return NULL;
    }
    stack->top = NULL;
    stack->last = NULL;
    stack->size = 0;
    return stack;
}
int add_to_stack(t_stack *stack, char *arg)
{
    int value;
    if (!is_valid_input(arg))
        return 0;
    value = ft_atoi(arg);
    if (has_repeated_numbers(stack, value))
    {
        write(2,"Error\n", 6);
        return 0;
    }
    t_node *new_node = create_node(value);
    if (new_node == NULL)
    {
        write(2,"Error\n", 6);
        return 0;
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
    return 1;
}
t_stack *initialize_stack(int argc, char **argv)
{
    int i;
    t_stack *stack;

    i = 1;
    stack = create_stack();
    if ((argc < 2) || (!stack))
    {
        write (2, "Error\n", 6);
        return NULL;
    }
    while (i < argc)
    {
        if (!add_to_stack(stack, argv[i]))
        {
            free_stack(stack);
            return NULL;
        }
        i++;
    }
    return stack;
}
void    free_stack(t_stack *stack)
{
    t_node *current = stack->top;
    t_node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}
