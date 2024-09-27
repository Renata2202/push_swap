/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:00:46 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/10/14 17:50:08 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*int main()
{
	int i1 = '2';
	int i2 = '3';
	int i3 = 'd';
	int i4 = '\n';

	printf("%d", ft_isascii(i1));
	printf("%d", ft_isascii(i2));
	printf("%d", ft_isascii(i3));
	printf("%d", ft_isascii(i4));
}*/
