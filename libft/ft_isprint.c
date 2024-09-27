/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:08:31 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/10/15 15:14:33 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c < 127);
}

/*
int main()
{
	int i1 = '2';
	int i2 = '3';
	int i3 = 'd';
	int i4 = '\n';

	printf("%d", ft_isprint(i1));
	printf("%d", ft_isprint(i2));
	printf("%d", ft_isprint(i3));
	printf("%d", ft_isprint(i4));
}
*/
