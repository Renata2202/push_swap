/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_node_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: renatanaesilva <renatanaesilva@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 22:49:20 by renatanaesi       #+#    #+#             */
/*   Updated: 2024/09/16 10:53:13 by renatanaesi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_stack_size(t_stack *stack)
{
    int size = 0;
    t_node *current = stack->top;

    while (current != NULL)
    {
        size++;
        current = current->next;
    }

    return size;
}
void fill_positions(t_stack *a, t_stack *b)
{
    if (!a || !a->top) // Verificação adicional para garantir que 'a' não seja NULL e não esteja vazia
        return;

    t_node *current;
    int position;

    current = a->top;
    position = 0;
    while (current)
    {
        current->position = position;
        current->dest_position = find_dest_position_desc(b, current->value);
        position++;
        current = current->next;
    }
    current = b->top;
    position = 0;
    while (current)
    {
        current->position = position;
        current->dest_position = find_dest_position_desc(a, current->value);
        position++;
        current = current->next;
    }
}

int find_dest_position_desc(t_stack *dest, int value_src)
{
    if (!dest || !dest->top) // Verificação adicional para garantir que 'dest' não seja NULL e não esteja vazia
        return 0;

    t_node *current;
    int position;

    current = dest->top;
    position = 0;

    while (current->next != dest->top)
    {
        if (value_src > current->value && value_src < current->next->value)
            return position + 1;
        current = current->next;
        position++;
    }

    // Se não encontrou a posição correta, verifica se deve ser inserido no final
    if (value_src > current->value)
        return position + 1;

    // Se o valor for menor que todos os valores na pilha dest, a posição é 0
    return 0;
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}
