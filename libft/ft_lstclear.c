/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:09:47 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/11/05 21:33:27 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))

{
	t_list	*new;
	t_list	*temp;

	if (!lst || !del)
		return ;
	new = *lst;
	while (new)
	{
		temp = new -> next;
		del(new -> content);
		free (new);
		new = temp;
	}
	*lst = NULL;
}
