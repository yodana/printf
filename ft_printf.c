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

int		ft_check_precision(int *i, const char *format)
{
	int res;
	int k;

	k = 0;
	if (format[k] != '.')
		return (0);
	res = ft_atoi(&format[1]);
	k++;
	*i = *i + 1;
	while (ft_isdigit(format[k]) == 1)
	{
		*i = *i + 1;
		k++;
	}
	return (res);
}
int		ft_check_champ(int *i, const char *format)
{
	int resultat;
	int k;

	k = 0;
	resultat = ft_atoi(format);
	while (ft_isdigit(format[k]) == 1 || format[k] == '-')
	{
		k++;
		*i = *i + 1;
	}
	return (resultat);
}
int		ft_is_conv(const char format)
{
	if (format == 'd' || format == 'f' || format == 'u' || 
			format == 'X' || format == 'x' || format == 'c' || 
				format == 's' || format == 'p' || format == 'i' || 
					format == 'o' || format == '%')
		return (1);
	return (0);
}

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
	if (format[0] == 'L')
		flags = 7;
	return (flags);
}
char	*ft_check_attribut(int *i, const char *format)
{
	char *attributs;
	int j;
	int k;
	char *res;

	k = 0;
	j = 0;
	res = ft_strnew(2);
	attributs = ft_fill_attribut();
	while (ft_is_conv(format[*i]) == 0 && ft_check_flags(&format[*i]) == 0 && (format[*i] == '0' || 
			ft_isdigit(format[*i]) == 0) && format[*i] != '-' && format[*i] != '.')
	{
		while (attributs[j])
		{
			if (attributs[j] == format[*i])
			{
				res[k] = attributs[j];
				k++;
			}
			j++;
		}
		j = 0;
		*i = *i + 1;
	}
	return (res);
}
#include <stdio.h>
int	ft_check_conv(const char *format, t_conv *lst_fct, va_list args)
{
	int	flags;
	int i;
	char *attribut;
	int champ;
	int precision;

	if (format[0] == '\0')
		return (0);
	i = 0;
	attribut = ft_check_attribut(&i, &format[i]);
	champ = ft_check_champ(&i, &format[i]);
	precision = ft_check_precision(&i, &format[i]);
	flags = ft_check_flags(&format[i]);
	i = i + (flags % 3);
	while (lst_fct != NULL)
	{
		if (format[i] == lst_fct->type)
		{
			lst_fct->precision = precision;
			lst_fct->champ = champ;
			lst_fct->attribut = ft_strdup(attribut);
			lst_fct->f(args, flags, lst_fct);
		}
		lst_fct = lst_fct->next;
	}
	return (i + 1);
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