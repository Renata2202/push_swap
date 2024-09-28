/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_treatment_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:11:05 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/28 19:33:24 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
    return (false);
}
int absolute_value(int n)
{
    if (n < 0)
        return (-n);
    else
        return (n);
}
