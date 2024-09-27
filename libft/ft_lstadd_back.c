/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 18:18:07 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/11/07 16:25:50 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *lst;
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	else
	{
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
}
/*
//function description
//The function ft_lstadd_back appends a new node 
//to the end of a linked list (lst) if new is not null, 
//handling cases where the list is empty or not.
#include <stdio.h>

int main(void)
{
	t_list *list;
	t_list *current;
	t_list *new;
	
	list = ft_lstnew("list1");
	list->next = ft_lstnew("list2");
	list->next->next = ft_lstnew("list3");
	list->next->next->next = ft_lstnew("list4");

	new = ft_lstnew("newlist");
	ft_lstadd_back(&list, new);
	current = list;
	while(current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
}*/
