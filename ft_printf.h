/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjiki <hyunjiki@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:57:48 by hyunjiki          #+#    #+#             */
/*   Updated: 2024/04/28 10:21:31 by hyunjiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_type_check(char c, va_list ap);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_itoa(int n);
int		ft_uitoa(unsigned int n);
int		ft_puthex(int n, char c);
int		ft_putpointer(unsigned long n);

#endif
