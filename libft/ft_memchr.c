/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:42:11 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/10/20 17:43:23 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)

{
	unsigned char		*ptr;

	ptr = ((unsigned char *)s);
	while (n > 0)
	{
		if (*ptr == (unsigned char)c)
			return ((void *) ptr);
		ptr++;
		n--;
	}
	return (0);
}
