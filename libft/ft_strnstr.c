/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:45:54 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/10/20 19:37:58 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)

{
	size_t	n;

	n = ft_strlen(little);
	if (*little == 0)
		return ((char *)big);
	if (len == 0)
		return (0);
	while (*big && n <= len)
	{
		if (*big == *little && ft_strncmp(big, little, n) == 0)
			return ((char *)big);
		big++;
		len--;
	}
	return (0);
}
