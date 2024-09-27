/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_treatment_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 09:29:06 by renatanaesi       #+#    #+#             */
/*   Updated: 2024/09/27 16:22:57 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define ERROR_INVALID_CHARACTERS 1

// Função para verificar se a string contém apenas números e delimitadores válidos
int is_valid_input(const char *input)
{
    while (*input)
    {
        if (*input == ' ' || *input == '\n' || *input == '\t' || *input == '"')
            input++;
        else if (*input == '-' || *input == '+')
        {
            input++;
            if (!(*input >= '0' && *input <= '9'))
            return 0;
        }
        else if (*input >= '0' && *input <= '9')
            input++;
        else
            return 0;
    }
    return 1;
}

bool has_repeated_numbers(t_stack *stack, int value)
{
    t_node *current = stack->top;
    while (current)
    {
        if (current->value == value)
            return true;
        current = current->next;
    }
    return false;
}
int absolute_value(int n)
{
    if (n < 0)
        return -n;
    else
        return n;
}
