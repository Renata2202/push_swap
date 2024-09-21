/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:16:54 by renatanaesi       #+#    #+#             */
/*   Updated: 2024/09/14 10:01:21 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap.h"

t_node *create_node(int value)
{
    t_node  *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
    {
        ft_printf("Erro: Falha na alocação de memória\n");
        return NULL;
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

t_stack *create_stack()
{
    t_stack *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
    {
        ft_printf("Erro: Falha na alocação de memória\n");
        return NULL;
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

int add_to_stack(t_stack *stack, char *arg)
{
    int value;
    if (!is_valid_input(arg))
    {
        ft_printf("Invalid input: %s\n", arg);
        return 0;
    }
    value = ft_atoi(arg);
    if (value < INT_MIN || value > INT_MAX)
    {
        ft_printf("Value out of range: %s\n", arg);
        return 0;
    }
    if (has_repeated_numbers(stack, value))
        {
        ft_printf("Duplicate value: %d\n", value);
        return 0;
        }
    return append(stack, value);
}

t_stack *initialize_stack(int argc, char **argv)
{
    int    i;
    t_stack    *stack;

    i = 1;
    stack = create_stack();

    if ((argc < 2) || (!stack))
    {
        ft_printf("ERROR\n");
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
void free_stack(t_stack *stack)
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
