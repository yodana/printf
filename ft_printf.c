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

void	ft_check_conv(char c, t_conv *lst_fct, va_list args)
{
	if (c == '\0')
		return ;
	while (lst_fct != NULL)
	{
		if (c == lst_fct->type)
		{
			lst_fct->f(args);
		}
		lst_fct = lst_fct->next;
	}
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
		{
			ft_check_conv(format[i + 1], lst_fct, args);
			i = i + 2;
		}
		if (format[i] != '%')
			ft_putchar(format[i++]);
	}
	ft_free_lst(lst_fct);
	return (i);
}