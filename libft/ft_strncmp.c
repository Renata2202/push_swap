/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:40:00 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/10/19 16:02:38 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <string.h>*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*int	main(void)
{
	char	a[] = "eu tentei ele tambem";
	char	b[] = "eu tentei ele tamm";
	unsigned int	c = 90;

	printf("res Ft_strncmp '%d'\n", ft_strncmp(a, b, c));
	printf("res strncmp '%d'\n", strncmp(a, b, c));
}*/
