/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:34:15 by renatanaesi       #+#    #+#             */
/*   Updated: 2024/07/27 12:58:03 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

#include "printf/ft_printf.h"

tyoedef struct s_stack_node
{
	int				value;
	int				index;
	int				current_position;
	int				previous_position;
	int				next_position;
	int				previous_value;
	int				next_value;

	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

#endif
