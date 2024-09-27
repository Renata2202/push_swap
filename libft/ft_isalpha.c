/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:45:46 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/10/15 16:10:15 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "libft.h"*/

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/*#include <stdio.h>
int main()
{
	int ch1 = 'a';
	int ch2 = 'G';
	int ch3 = '\0';
	int ch4 = '0';
	printf("%d", ft_isalpha(ch1));
	printf("%d", ft_isalpha(ch2));
	printf("%d", ft_isalpha(ch3));
	printf("%d", ft_isalpha(ch4));
}
*/
