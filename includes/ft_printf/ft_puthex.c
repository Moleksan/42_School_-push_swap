/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:44:17 by moleksan          #+#    #+#             */
/*   Updated: 2024/08/14 14:44:20 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long nbr, char c)
{
	int	len;

	len = 0;
	if (nbr > 15)
		len += ft_puthex(nbr / 16, c);
	if (c == 'x')
		len += write(1, &"0123456789abcdef"[nbr % 16], 1);
	else
		len += write(1, &"0123456789ABCDEF"[nbr % 16], 1);
	return (len);
}
