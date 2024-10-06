/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:43:57 by moleksan          #+#    #+#             */
/*   Updated: 2024/08/14 14:44:01 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(unsigned long addr)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_puthex(addr, 'x');
	return (len);
}
