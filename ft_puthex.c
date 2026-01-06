/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjiki <hyunjiki@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:41:21 by hyunjiki          #+#    #+#             */
/*   Updated: 2024/04/16 16:52:32 by hyunjiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(int n, char c)
{
	char			*hex;
	int				sum;
	unsigned int	i;

	sum = 0;
	i = (unsigned int) n;
	hex = "0123456789abcdef";
	if (c == 'X')
		hex = "0123456789ABCDEF";
	if (i > 15)
		sum += ft_puthex((i / 16), c);
	sum += ft_putchar(hex[i % 16]);
	return (sum);
}
