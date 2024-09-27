/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <rnunes-a@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:47:41 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/11/03 11:44:29 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)

{
	long	l;

	l = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		l = l * -1;
	}
	if (l > 9)
	{
		ft_putnbr_fd(l / 10, fd);
	}
	ft_putchar_fd((l % 10) + '0', fd);
}

/*int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	return (0);
}*/
