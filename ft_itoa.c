/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjiki <hyunjiki@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:52:44 by hyunjiki          #+#    #+#             */
/*   Updated: 2024/04/28 10:25:25 by hyunjiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_i_putnbr(long long n)
{
	unsigned int	num;
	char			c;

	if (n < 0)
	{
		num = -n;
		write(1, "-", 1);
	}
	else
		num = n;
	if ((num / 10) != 0)
		ft_i_putnbr(num / 10);
	c = (num % 10) + '0';
	write(1, &c, 1);
	return ;
}

int	ft_itoa(int n)
{
	size_t		len;
	long long	num;

	len = 0;
	num = n;
	if (num < 1)
	{
		num *= -1;
		len++;
	}
	while (num)
	{
		len++;
		num /= 10;
	}
	num = n;
	ft_i_putnbr(num);
	return (len);
}
