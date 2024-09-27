/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:13:46 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/11/05 13:42:45 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char const *s, char c)
{
	int	w;
	int	i;

	w = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			w++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (w);
}

void	ft_free(char **arr, int i)
{
	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

static char	**reduce_str(char **frs, const char *s, char c, size_t numwords)
{
	const char	*start;

	auto size_t i = 0;
	while (i < numwords)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			start = s;
			while (*s && *s != c)
				s++;
			frs[i] = ft_substr(start, 0, s - start);
			if (!frs[i])
			{
				ft_free(frs, i);
				return (NULL);
			}
		}
		i++;
	}
	frs[i] = NULL;
	return (frs);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**newstr;

	if (!s)
		return (0);
	size = count_word(s, c);
	newstr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!newstr)
		return (0);
	newstr = reduce_str (newstr, s, c, size);
	return (newstr);
}

/*int	main()
{
	char	**new;
       	const char 	*s = "**aa***bbb***";
	char	c = '*';
	new = ft_split(s, c);
	size_t	i;
	if (new)
	{
		i = 0;
		while (new[i])
		{
			ft_putstr_fd(new[i], 1);
			ft_putchar_fd('\n', 1);
			i++;
		}
	}
}*/
