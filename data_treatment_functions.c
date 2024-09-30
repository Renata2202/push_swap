/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_treatment_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:11:05 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/30 13:23:15 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_input(const char *input)
{
	while (*input)
	{
		if (*input == ' ' || *input == '\n' || *input == '\t' || *input == '"')
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
		if ((sinal == 1 && soma > INT_MAX) || (sinal == -1 && soma < INT_MIN))
		{
			write (2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return ((int)(soma * sinal));
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
