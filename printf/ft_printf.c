/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnunes-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:30:39 by rnunes-a          #+#    #+#             */
/*   Updated: 2023/11/18 22:47:19 by rnunes-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}

int	print_digit(long n, int base, int uclc)
{
	auto char *symbols = "0123456789abcdef";
	char	*symbols2 =  "0123456789ABCDEF";
	int		count;

	if (uclc == 2)
	{
		if (n == 0)
			return (write(1, "(nil)", 5));
		else
			write (1, "0x", 2);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		return (print_digit (-n, base, 0) + 1);
	}
	else if (n < base && (uclc == 0 || uclc == 2))
		return (print_char(symbols[n]));
	else if (n < base && uclc == 1)
		return (print_char(symbols2[n]));
	else
	{
		count = print_digit (n / base, base, uclc);
		return (count + print_digit(n % base, base, uclc));
	}
}

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char (va_arg (ap, int));
	else if (specifier == 's')
		count += print_str(va_arg (ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)va_arg (ap, int), 10, 0);
	else if (specifier == 'u')
		count += print_digit((long)va_arg (ap, unsigned int), 10, 0);
	else if (specifier == 'x')
		count += print_digit((long)va_arg (ap, unsigned int), 16, 0);
	else if (specifier == 'X')
		count += print_digit((long)va_arg (ap, unsigned int), 16, 1);
	else if (specifier == 'p')
		count += (print_digit((long)va_arg (ap, unsigned int), 16, 2));
	else
		count += print_char (va_arg (ap, int));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int			count;
	va_list		ap;

	va_start (ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

/*int     main()
{
    int     count;

    count = ft_printf("hrello %s", "John");
    ft_printf("The chars written are %d\n", count);
*/
