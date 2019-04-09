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

int		ft_check_flags(const char *format)
{
	int flags;

	flags = 0;
	if (format[0] == 'h')
	{
		flags = 1;
		if (format[1] == 'h')
			flags++;		
	}
	if (format[0] == 'l')
	{
		flags = 4;
		if (format[1] == 'l')
			flags++;
	}
	return (flags);
}

int	ft_check_conv(const char *format, t_conv *lst_fct, va_list args)
{
	int	flags;
	int i;

	if (format[0] == '\0')
		return (0);
	flags = ft_check_flags(format);
	i = flags % 3;
	while (lst_fct != NULL)
	{
		if (format[i] == lst_fct->type)
			lst_fct->f(args, flags, lst_fct->display);
		lst_fct = lst_fct->next;
	}
	return ((flags % 3) + 1);
}

int		ft_printf(const char *format, ...)
{
	int i;
	va_list args;
	t_conv	*lst_fct;

	va_start(args, format);
	if (!(lst_fct = ft_create_lst()))
		return (-1);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = i + ft_check_conv(&format[i + 1], lst_fct, args) + 1;
		if (format[i] && format[i] != '%')
			ft_putchar(format[i++]);
	}
	ft_free_lst(lst_fct);
	return (i);
}