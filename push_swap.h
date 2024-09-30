/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:34:15 by renatanaesi       #+#    #+#             */
/*   Updated: 2024/09/30 14:08:56 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				val;
	int				position;
	int				cost_a;
	int				cost_b;
	int				a_goal_pos;
	int				trg_pos;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*last;
	int		size;
}	t_stack;

// swap_functions.c
void	swap_top_two(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// rotate_functions.c
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

// reverse_rotate_functions.c
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

// push_functions.c
void	push_top(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
int		append(t_stack *stack, int val);

// stack_functions.c
t_node	*create_node(int val);
void	create_stack(t_stack **stack);
t_stack	*initialize_stack(int argc, char **argv);
int		add_to_stack(t_stack *stack, char *arg);
int		check_input(t_stack *stack, char *arg, int *val);
void	free_stack(t_stack *stack);

// sort_stack_functions.c
void	manage_small_stack(t_stack **stack);
void	sort_three_asc(t_stack **stack);
bool	is_sorted_asc(t_stack *stack);
void	manage_big_stack(t_stack **a, t_stack **b);

//data_node_functions.c
int		get_stack_size(t_stack *stack);
void	start_b(t_stack **a, t_stack **b);

// move_functions.c
void	send_values_to_b(t_stack **a, t_stack **b);
void	get_value_position(t_stack **stack);
void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void	rotate_single(t_stack **a, t_stack **b, int cost_a, int cost_b);

//data_treatment_functions.c
int		is_valid_input(const char *input);
int		is_in_int_range(const char *arg);
int		ft_atoi(const char *nptr);
bool	has_repeated_numbers(t_stack *stack, int val);
int		absol_value(int n);

// push_swap.c
int		main(int argc, char **argv);
void	print_stack(t_stack *stack);
void	manage_stacks(t_stack **a, t_stack **b);
void	free_stack(t_stack *stack);

// fill_positions_functions.c
void	fill_positions(t_stack **a, t_stack **b);
void	fill_target_position(t_stack **stack);
void	get_cost(t_stack **a, t_stack **b);
int		get_min_position(t_stack *stack);
int		get_trg_a(t_stack **a, int b_targ_pos, int a_goal_pos);

#endif // PUSH_SWAP_H
