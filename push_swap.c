/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:34:25 by renatanaesi       #+#    #+#             */
/*   Updated: 2024/09/16 10:56:17 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = initialize_stack(argc, argv);
    b = create_stack();
    print_stack(a);
    if (get_stack_size(a) <= 3)
    {
        manage_smal_stack(a);
        print_stack(a);
        return 0;
    }
    else
    {
        pb(a, b);
        pb(a, b);
        if (b->top->value < b->top->next->value)
            sb(b);
    }
    fill_positions(a, b);
    while (!is_sorted_asc(a) && get_stack_size(a) > 3)
    {
        pb(a, b);
    }
    print_stack(a);
    print_stack(b);
    while (get_stack_size(b) > 0)
    {
        pa(a, b);
    }
    free_stack(b);
    print_stack(a);
    return 0; // Encerra o programa com sucesso
}
/*void print_stack(t_stack *stack)
{
    t_node *current = stack->top;

    // Imprime o cabeçalho das colunas
    ft_printf("Stack address: %p\n", (void *)stack);
    ft_printf("Stack size: %d\n", stack->size);
    //ft_printf("Value\n"); // Cabeçalho das colunas

    // Percorre a pilha e imprime os valores de cada nó
    while (current)
    {
        ft_printf("%d\n", current->value);
        current = current->next;
    }
    printf("\n");
}*/
void print_stack(t_stack *stack)
{
    t_node *current = stack->top;

    // Imprime o cabeçalho das colunas
    ft_printf("Stack address: %p\n", (void *)stack);
    ft_printf("Stack size: %d\n", stack->size);
    ft_printf("Value\tPosition\tdest_position\n"); // Cabeçalho das colunas

    // Percorre a pilha e imprime os valores de cada nó
    while (current)
    {
        ft_printf("%d\t%d\t%d\n", current->value, current->position, current->dest_position);
        current = current->next;
    }
    printf("\n");
}
