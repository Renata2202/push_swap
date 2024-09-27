/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:00:28 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/10/19 11:54:13 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;
	size_t					i;

	if (!src && !dest)
		return (dest);
	d = dest;
	s = src;
	i = 0;
	while (n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (dest);
}
/*int main()
{
	const char src[] = "PRIMEIRA tentativa";
	char    dest[30] = "123456789012345678901234567890";
	char    dest1[30] = "123456789012345678901234567890";    
	printf("%s \n", dest);
 
	ft_memcpy(dest, src, 22);
	printf("%s\n", dest);
	memcpy(dest1, src, 30);
	printf("%s\n", dest1);	
}*/
