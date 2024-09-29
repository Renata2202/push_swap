/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:24:31 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/29 19:38:38 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}
/*#include <stdio.h>
int main(void)
{
	//declare nods
	t_list *elem;
	t_list *in_front;
	t_list *current;

	//create new node
	elem = ft_lstnew("first node");
	elem->next = ft_lstnew("second node");
	in_front = ft_lstnew("In Front");

	//use func to add in front
	ft_lstadd_front(&elem, in_front);

	//print alone to test
	//printf("This is the first => %s\n", (char *)elem->content);

	//print all in order
	current = elem;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
}*/
