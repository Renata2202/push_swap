/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:15:35 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/10/27 14:21:44 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)

{
	char		*s3;
	size_t		lstr1;
	size_t		lstr2;

	lstr1 = ft_strlen(s1);
	lstr2 = ft_strlen(s2);
	s3 = (char *)malloc((lstr1 + lstr2 + 1) * sizeof(char));
	if (!s3)
		return (0);
	ft_strlcpy(s3, s1, lstr1 + 1);
	ft_strlcpy(s3 + lstr1, s2, lstr2 + 1);
	return (s3);
}
