/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:00:47 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/10/15 19:21:30 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!src && !dest)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	while (n--)
		d[n] = s[n];
	return (dest);
}

/*int main()
{
	char	src[] = "Vou ser copiado.";
	char	dest[1];

	ft_memmove(dest, src, 10);
    printf("%s, \n", dest);
}*/
