/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:39:30 by yodana            #+#    #+#             */
/*   Updated: 2019/04/01 15:40:50 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "stdio.h"

char	ft_char(va_list args, char c)
{
	return ('c');
}

void	ft_create_lst()
{
	char tab[1];
	char (*tab_ft[1])(va_list, char);
	tab[0] = 'c';
	tab_ft[0] = ft_char;
	return (0);
}

int		ft_printf(const char *format, ...)
{
	int i;
	va_list args;

	va_start(args, format);
	va_arg(args, char*);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_putchar(format[i++]);
	}
	return (i);
}