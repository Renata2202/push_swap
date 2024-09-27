/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:49:22 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/10/29 18:19:05 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	ls;
	char	*ns;

	ls = ft_strlen(s);
	ns = (char *)malloc(sizeof(char) * (ls + 1));
	if (!ns)
		return (0);
	ns[ls] = '\0';
	while (ls > 0)
	{
		ls--;
		ns[ls] = f(ls, s[ls]);
	}
	return (ns);
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
