/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 20:01:33 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/10/19 15:31:21 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*pt_src;

	pt_src = (char *)src;
	i = 0;
	j = 0;
	if (size == 0)
		return (i + ft_strlen(src));
	while (i < size && (dst[i] != '\0'))
		i++;
	while (i + j < size - 1 && (pt_src[j] != '\0'))
	{
		dst[i + j] = pt_src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	while (pt_src[j])
		j++;
	return (j + i);
}

/*# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int   main(void)
{
	char    a[] = "the cake is a lie !\0I'm hidden lol\r\n";
	char    b[] = "there is no stars in the sky";
        char buff1[0xF00] = "there is no stars in the sky";
 	char buff2[0xF00] = "there is no stars in the sky";
 	size_t max = strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;
 	size_t r1 = strlcat(buff1, a, max);
 	size_t r2 = ft_strlcat(buff2, a, max);
 
 	if (r1 != r2)
 		return (0);
 	char s1[4] = "";
 	char s2[4] = "";
 	r1 = strlcat(s1, "thx to ntoniolo for this test !", 4);
  	r2 = ft_strlcat(s2, "thx to ntoniolo for this test !", 4);
  	if (r1 != r2)
 		return (0);
 	return(1);

}*/
