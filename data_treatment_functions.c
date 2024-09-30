/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_treatment_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:11:05 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/30 14:11:03 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_input(const char *input)
{
	while (*input)
	{
		if (*input == ' ' || *input == '\n' || *input == '\t')
			input++;
		else if (*input == '-' || *input == '+')
		{
			input++;
			if (!(*input >= '0' && *input <= '9'))
			{
				write (2, "Error\n", 6);
				return (0);
			}
		}
		else if (*input >= '0' && *input <= '9')
			input++;
		else
		{
			write (2, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sinal;
	long long	soma;

	i = 0;
	sinal = 1;
	soma = 0;
	while ((nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sinal *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		soma = ((nptr[i] - '0') + (soma * 10));
		i++;
	}
	return ((int)(soma * sinal));
}

int	is_in_int_range(const char *arg)
{
    long long result = 0;
    int sign = 1;
    const long long int_min = (long long)INT_MIN;
    const long long int_max = (long long)INT_MAX;

    if (*arg == '-' || *arg == '+')
    {
        if (*arg == '-')
            sign = -1;
        arg++;
    }
    while (*arg)
    {
        if (*arg < '0' || *arg > '9')
            return (0);
        result = result * 10 + (*arg - '0');
        if (sign == 1 && result > int_max)
            return (0);
        if (sign == -1 && -result < int_min)
            return (0);
        arg++;
    }
    return (1);
}

bool	has_repeated_numbers(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->val == value)
			return (true);
		current = current->next;
	}
	return (false);
}

int	absol_value(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}
