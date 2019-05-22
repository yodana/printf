/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 03:10:31 by yodana            #+#    #+#             */
/*   Updated: 2019/05/02 11:01:10 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
char	*ft_dtoa(long double m, int size)
{
	int		i;
	char	*res;
	int		j;

	i = 0;
	j = 0;
	if (!(res = ft_strnew(size)))
		return (NULL);
	j = (int)m;
	while (i != size)
	{
		if (i == 1)
		{
			res[i] = '.';
			i++;
		}
		res[i] = j + '0';
		m = m - j;
		m = m * 10;
		j = (int)m;
		i++;
	}
	return (res);
}

char	*ft_float_round(int i, char *print, int size)
{
	if (print[i] >= '5')
	{
		i--;
		while (i != 0 && (print[i] == '9' || print[i] == '.'))
		{
			if (print[i] != '.')
				print[i] = '0';
			i--;
		}
		if (print[i] == '9' && i == 0)
		{
			print[i] = '0';
			print = ft_strjoin("1", print);
		}
		else
			print[i] = print[i] + 1;
	}
	return (ft_strsub(print, 0, size));
}

char	*ft_print_float(char *res, int precision, int stop)
{
	int		i;
	char	*print;
	int		comma;

	comma = 0;
	i = 0;
	if (!res || !(print = ft_strnew(ft_strlen(res) + 1)))
		return (NULL);
	while (res[i] != '.')
	{
		print[i] = res[i];
		i++;
		comma++;
	}
	while (stop++ != precision + 1)
	{
		print[i] = res[i];
		i++;
	}
	res = ft_float_round(i - 1, print, comma + precision);
	ft_strdel(&print);
	if (precision == 1)
		res = ft_strsub(res, 0, comma);
	return (res);
}

int		ft_check_excep(unsigned int exposant, char *m, int signe, t_conv* lst_fct)
{
	if (!m)
		return (1);
	if (exposant >= 32767)
	{
		if (m[1] == '1')
		{
			lst_fct->final = ft_strdup("nan");
			lst_fct->final = ft_attribut(1, lst_fct);
			ft_putstr(lst_fct->final);
			return (1);
		}
		if (signe == 1)
			lst_fct->final = ft_strdup("-inf");
		else
		{
			lst_fct->final = ft_strdup("inf");
		}
		lst_fct->final = ft_attribut(1, lst_fct);
		ft_putstr(lst_fct->final);
		return (1);
	}
	return (0);
}

int		ft_conv_f(va_list args, int flags, t_conv *lst_fct)
{
	float_cast	d1;
	char		*res_final;
	char		*m_2;

	if (lst_fct->precision == 0)
		lst_fct->precision = 7;
	if (flags == FL)
		d1.f = va_arg(args, long double);
	else
		d1.f = va_arg(args, double);
	m_2 = ft_i_to_bi(d1.parts.m);
	if (ft_check_excep(d1.parts.e, m_2, d1.parts.sign, lst_fct))
	{
		ft_strdel(&m_2);
		return (0);
	}
	res_final = ft_bi_to_dec(m_2, 0, 1, 66 + lst_fct->precision);
	res_final = ft_calc_exposant(d1.f, res_final, d1.parts.e);
	lst_fct->final = ft_strdup(ft_print_float(res_final, lst_fct->precision, 0));
	if (d1.parts.sign == 1)
		lst_fct->final = ft_strjoin_fr("-", lst_fct->final, 2);
	lst_fct->final = ft_attribut(d1.f, lst_fct);
	ft_putstr(lst_fct->final);
	ft_strdel(&res_final);
	return (0);
}
