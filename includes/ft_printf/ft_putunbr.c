/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:44:34 by moleksan          #+#    #+#             */
/*   Updated: 2024/08/14 14:44:37 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr > 9)
		len += ft_putunbr(nbr / 10);
	len += ft_putchar(nbr % 10 + '0');
	return (len);
}
