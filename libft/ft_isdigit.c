/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 11:30:42 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/10/15 15:10:36 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int d)
{
	return (d >= '0' && d <= '9');
}

/*
int main()
{
	int i1 = '2';
	int i2 = '3';
	int i3 = 'd';
	int i4 = '\n';

	printf("%d", ft_isdigit(i1));
	printf("%d", ft_isdigit(i2));
	printf("%d", ft_isdigit(i3));
	printf("%d", ft_isdigit(i4));
}*/
