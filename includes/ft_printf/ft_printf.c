/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:43:00 by moleksan          #+#    #+#             */
/*   Updated: 2024/08/14 14:43:04 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_type(va_list argp, const char *format, int *len)
{
	if (*format == '%')
		*len += ft_putchar('%');
	else if (*format == 'c')
		*len += ft_putchar((char)va_arg(argp, int));
	else if (*format == 's')
		*len += ft_putstr(va_arg(argp, char *));
	else if (*format == 'i' || *format == 'd')
		*len += ft_putnbr(va_arg(argp, int));
	else if (*format == 'u')
		*len += ft_putunbr(va_arg(argp, unsigned int));
	else if (*format == 'x' || *format == 'X')
		*len += ft_puthex(va_arg(argp, unsigned int), *format);
	else if (*format == 'p')
		*len += ft_putaddr(va_arg(argp, unsigned long));
	else
		*len += ft_putchar(*format);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	argp;

	len = 0;
	va_start(argp, format);
	while (*format != '\0')
	{
		if (*format == '%' && !*(format + 1))
			break ;
		if (*format == '%')
		{
			format++;
			check_type(argp, format, &len);
		}
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(argp);
	return (len);
}
