/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjiki <hyunjiki@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:33:17 by hyunjiki          #+#    #+#             */
/*   Updated: 2024/04/28 11:07:13 by hyunjiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_u_putnbr(unsigned int n)
{
	char	c;

	if ((n / 10) != 0)
		ft_u_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	ft_uitoa(unsigned int n)
{
	int				len;
	unsigned int	num;

	len = 0;
	num = n;
	if (n == 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	ft_u_putnbr(num);
	return (len);
}
