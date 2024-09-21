/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:34:15 by renatanaesi       #+#    #+#             */
/*   Updated: 2024/09/16 10:33:06 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define SWAP 1
#define ROTATE 2
#define REVERSE_ROTATE 3

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

#include "printf/ft_printf.h"
#include "libft/libft.h"

// Definição da estrutura do nó
// Definição da estrutura da pilha
typedef struct s_node
{
    int value;
    int position;
    int dest_position;
    struct s_node *next;
} t_node;;

typedef struct s_stack
{
    t_node *top;  // Campo para o topo da pilha baseada em nós
    t_node *last;  // Campo para o último nó da pilha
    int *data;
    int size;
}
t_stack;

// swap_functions.c
void    swap_top_two(t_stack *stack);
void    sa(t_stack *a);
void    sb(t_stack *b);
void    sab(t_stack *a, t_stack *b);

// rotate_functions.c
void    rotate(t_stack *stack);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);

// reverse_rotate_functions.c
void    reverse_rotate(t_stack *stack);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

// push_functions.c
void    push_top(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
int     append(t_stack *stack, int value);

// stack_functions.c
t_node  *create_node(int value);
t_stack *create_stack();
t_stack *initialize_stack(int argc, char **argv);
int     add_to_stack(t_stack *stack, char *arg);
void    free_stack(t_stack *stack);

// sort_stack_functions.c
void    manage_smal_stack(t_stack *stack);
void    sort_three_asc(t_stack *stack);
bool    is_sorted_asc(t_stack *stack);

//data_node_functions.c
int     get_stack_size(t_stack *stack);
int     find_dest_position_desc(t_stack *dest, int value_src);
void    fill_positions(t_stack *a, t_stack *b);
//int     best_price_position_asc(t_stack *a, t_stack *b, int position, int dest_position);
//void    best_price_position_desc(t_stack *a, t_stack *b, int position, int dest_position);
int     max(int a, int b);
int     min(int a, int b);

//data_treatment_functions.c
int     is_valid_input(const char *input);
bool    has_repeated_numbers(t_stack *stack, int value);


// push_swap.c
int main(int argc, char **argv);
void print_stack(t_stack *stack);

#endif // PUSH_SWAP_H
