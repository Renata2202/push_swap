/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:21:28 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/10/21 20:47:02 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	char	*substr;
	size_t	j;

	j = 0;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = (ft_strlen(s) - start);
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (0);
	while (j < len)
	{
		substr[j] = s[start];
		start++;
		j++;
	}
	substr[j] = 0;
	return (substr);
}
