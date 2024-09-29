/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:12:46 by rnunes-a          #+#    #+#             */
/*   Updated: 2024/09/29 19:38:06 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	ls;

	ls = ft_strlen(s);
	while (ls > 0)
	{
		ls--;
		f(ls, &s[ls]);
	}
}
/*char    clean(unsigned int i, char c)
{
        if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
                c = ' ';
        return (c);
}
int     main()
{
        ft_putstr_fd(ft_strmapi("a*b*c*d", clean), 1);
}*/
