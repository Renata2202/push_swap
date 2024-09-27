/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:44:55 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/10/15 15:47:23 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)

{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*#include <stdio.h>
int main()
{
	int i1 = '2';
	int i2 = '3';
	int i3 = 'd';
	int i4 = '\n';

	printf("%d", ft_isalnum(i1));
	printf("%d", ft_isalnum(i2));
	printf("%d", ft_isalnum(i3));
	printf("%d", ft_isalnum(i4));
}*/
