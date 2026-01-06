/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjiki <hyunjiki@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:14:25 by hyunjiki          #+#    #+#             */
/*   Updated: 2024/04/28 10:55:37 by hyunjiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_type_check(char c, va_list ap)
{
	unsigned long	ptr;

	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'c')
		return (ft_putchar((char)va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(ap, int)));
	if (c == 'u')
		return (ft_uitoa(va_arg(ap, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(ap, int), c));
	if (c == 'p')
	{
		ptr = va_arg(ap, unsigned long);
		if (ptr == 0)
			return (ft_putstr("(nil)"));
		else
			return (ft_putstr("0x") + ft_putpointer(ptr));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		num;

	if (!format)
		return (-1);
	va_start(ap, format);
	i = 0;
	num = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break ;
			num += ft_type_check(format[i], ap);
		}
		else
			num += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (num);
}
/*
int main(void)
{
	int num;
	void *ptr = &num;
	printf("----printf----\n");
	printf("return : %d\n\n", printf("%%\n"));
	printf("return : %d\n\n", printf("%c\n", 'a'));
	printf("return : %d\n\n", printf("%s\n", "abc"));
	printf("return : %d\n\n", printf("%d\n", 0));
	printf("return : %d\n\n", printf("%i\n", -123));
	printf("return : %d\n\n", printf("%u\n", 123));
	printf("return : %d\n\n", printf("%x\n", 1000));
	printf("return : %d\n\n", printf("%X\n", 1000));
	printf("return : %d\n\n", printf("%p\n", ptr));

	ft_printf("----ft_printf----\n");
	ft_printf("ft_return : %d\n\n", ft_printf("%%\n"));
	ft_printf("ft_return : %d\n\n", ft_printf("%c\n", 'a'));
	ft_printf("ft_return : %d\n\n", ft_printf("%s\n", "abc"));
	ft_printf("ft_return : %d\n\n", ft_printf("%d\n", 0));
	ft_printf("ft_return : %d\n\n", ft_printf("%i\n", -123));
	ft_printf("ft_return : %d\n\n", ft_printf("%u\n", 123));
	ft_printf("ft_return : %d\n\n", ft_printf("%x\n", 1000));
	ft_printf("ft_return : %d\n\n", ft_printf("%X\n", 1000));
	ft_printf("ft_return : %d\n\n", ft_printf("%p\n", ptr));
}*/
