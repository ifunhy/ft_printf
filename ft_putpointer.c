/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjiki <hyunjiki@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:43:15 by hyunjiki          #+#    #+#             */
/*   Updated: 2024/04/16 16:52:39 by hyunjiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(unsigned long n)
{
	char	*hex;
	int		sum;

	sum = 0;
	hex = "0123456789abcdef";
	if (n)
	{
		sum += ft_putpointer(n / 16);
		sum += ft_putchar(hex[n % 16]);
	}
	return (sum);
}
