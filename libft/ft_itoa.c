/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:58:00 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/10/29 13:34:57 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_index(long j)

{
	int		i;

	i = 0;
	if (j <= 0)
		i++;
	while (j != 0)
	{
		j = (j / 10);
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*strl;
	size_t	t;
	long	ln;

	ln = n;
	t = ft_get_index(ln);
	strl = (char *)malloc((t + 1) * sizeof(char));
	if (!strl)
		return (0);
	strl[t] = '\0';
	t--;
	if (ln < 0)
	{
		strl[0] = '-';
		ln = (ln * -1);
	}
	while (ln > 9 && t > 0)
	{
		strl[t] = ((ln % 10) + '0');
		ln = (ln / 10);
		t--;
	}
	strl[t] = ln + '0';
	return (strl);
}
/*
int	main(void)
{
	char *c = ft_itoa(-123451);
	printf ("%s", c);
} */
