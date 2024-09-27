/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:24:41 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/10/27 19:51:39 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	str;
	size_t	end;

	str = 0;
	end = ft_strlen(s1) - 1;
	while (s1[str] && ft_strchr(set, s1[str]))
		str++;
	while (s1[end] && ft_strchr(set, s1[end]))
		end--;
	s2 = ft_substr(s1, str, (end - str + 1));
	return (s2);
}
/*
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)

{
	char		*tmp1;
	char		*strim;
	size_t		tt;
	int			i;
	int			j;

	if (!s1 || !set)
		return (0);
	tt = ft_strlen(s1);
	i = 0;
	while (s1[i] == *set)
		i++;
	j = 0;
	tmp1 = (char *)malloc((tt - i + 1) * sizeof(char));
	while (*s1)
	{
		tmp1[j] = s1[i];
		i++;
		j++;
	}
	while (tmp1[j] == *set)
		j--;
	strim = (char *)malloc((j + 1) * sizeof(char));
	ft_strlcpy(strim, tmp1, j);
	strim[j + 1] = 0;
	return (strim);
}*/
