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

int	ft_check_precision(int *i, const char *format)
{
	int res;
	int k;

	k = 0;
	res = 0;
	if (format[k] != '.')
		return (0);
	res = ft_atoi(&format[1]) + 1;
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
	if (format[k] == '-' && format[k + 1] == '#')
		resultat = ft_atoi(&format[k + 2]) * -1;
	else if (format[k] == '-' && format[k + 1] == '+')
		resultat = ft_atoi(&format[k + 1]) * -1;
	else
		resultat = ft_atoi(format);
	while (ft_isdigit(format[k]) == 1 || format[k] == '-' || format[k] == '+' || format[k] == '#')
	{
		k++;
		*i = *i + 1;
	}
	return (resultat);
}
int		ft_is_attribut(const char format)
{
	if (format == '#' || format == '0' || format == '-' || 
			format == '+' || format == ' ')
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
	if (!(res = ft_strnew(10)))
		return (NULL);
	if (!(attributs = ft_fill_attribut()))
		return (NULL);
	while (ft_is_attribut(format[*i]) == 1 && (format[*i] == '0' || 
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
	if ((format[*i + 1] && format[*i + 1] == '+') || (format[*i + 2] && format[*i + 2] == '+'))
	{
		if (!(res = ft_strjoin_fr(res, "+", 1)))
			return (NULL);
	}
	if (format[*i + 1] && format[*i + 1] == '#')
	{
		if (!(res = ft_strjoin_fr(res, "#", 1)))
			return (NULL);
	}
	ft_strdel(&attributs);
	return (res);
}

int	ft_check_conv(const char *format, t_conv *lst_fct, va_list args, int *d)
{
	int	flags;
	int i;
	char *attribut;
	int champ;
	int precision;
	int size;

	size = 0;
	(void)args;
	if (format[0] == '\0')
		return (0);
	i = 0;
	if (!(attribut = ft_check_attribut(&i, &format[i])))
		return (1);
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
			if (!(lst_fct->attribut = ft_strdup(attribut)))
				return (1);
			size = lst_fct->f(args, flags, lst_fct);
			ft_strdel(&lst_fct->attribut);
		}
		lst_fct = lst_fct->next;
	}
	ft_strdel(&attribut);
	*d = *d + i + 2;
	return (size);
}

int		ft_printf(const char *format, ...)
{
	int i;
	va_list args;
	t_conv	*lst_fct;
	int size;

	size = 0;
	i = 0;
	va_start(args, format);
	if (!format || !(lst_fct = ft_create_lst()))
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
			size = size + ft_check_conv(&format[i + 1], lst_fct, args, &i);
		if (format[i] && format[i] != '%')
		{
			ft_putchar(format[i++]);
			size++;
		}
	}
	ft_free_lst(lst_fct);
	return (size);
}