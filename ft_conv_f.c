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

char	*ft_float_round(int i, char *print, int size)
{
	printf("round == %c\n",print[i]);
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
int		ft_calc_comma(char *res)
{
	int i;

	i = 0;
	while (res[i] && res[i] != '.')
		i++;
	return (i);
}
char	*ft_print_float(char *res, t_conv *lst_fct, int stop)
{
	int		i;
	char	*print;
	int		comma;
	int e;
	e = 0;
	if (lst_fct->type == 'e')
		e++;
	comma = ft_calc_comma(res);
	i = 0;
	if (!res || !(print = ft_strnew(ft_strlen(res) + 1)))
		return (NULL);
	while (res[i] != '.')
	{
		print[i] = res[i];
		i++;
	}
	while (stop++ != lst_fct->precision + 20)
	{
		print[i] = res[i];
		i++;
	}
	//if (lst_fct->type == 'e' && lst_fct->precision == 0)
		//lst_fct->precision++;
	if (ft_check_float_round(&print[comma - 1], lst_fct->precision) == 1)
	{
		printf("lol");
		res = ft_float_round(i - 20 + e, print, comma + lst_fct->precision);
	}
	//printf("res after precision %s", res);
	ft_strdel(&print);
	comma = ft_calc_comma(res);
	if (lst_fct->type == 'e')
		res = ft_conv_e(lst_fct, res, comma);
	if (lst_fct->precision == 1 && lst_fct->type != 'e')
		return (ft_strsub(res, 0, comma));
	return (res);
}

int		ft_check_excep(unsigned int exposant, char *m
, int signe, t_conv *lst_fct)
{
	int size;

	if (!m || exposant < 32767)
		return (-1);
	if (m[1] == '1')
	{
		lst_fct->final = ft_strdup("nan");
		lst_fct->final = ft_space(1, lst_fct, ft_strlen(lst_fct->final));
		size = ft_strlen(lst_fct->final);
		ft_putstr(lst_fct->final);
		ft_strdel(&lst_fct->final);
		return (size);
	}
	lst_fct->final = signe == 1 ? ft_strdup("-inf") : ft_strdup("inf");
	if (ft_strrchr(lst_fct->attribut, '+')
			&& ft_strrchr(lst_fct->final, '-') == NULL)
		lst_fct->final = ft_plus(lst_fct);
	lst_fct->final = ft_space(1, lst_fct, ft_strlen(lst_fct->final));
	size = ft_strlen(lst_fct->final);
	ft_putstr(lst_fct->final);
	ft_strdel(&lst_fct->final);
	return (size);
}

int		ft_conv_f(t_conv *lst_fct, va_list args, int flags)
{
	t_float		d1;
	char		*res_final;
	char		*m_2;
	int			size;

	lst_fct->precision = lst_fct->precision == 0 ? 7 : lst_fct->precision;
	lst_fct->precision = lst_fct->type == 'e' ? lst_fct->precision - 1 : lst_fct->precision;
//	printf("precision == %c\n",lst_fct->type);
	d1.f = flags == FL ? va_arg(args, long double) : va_arg(args, double);
	m_2 = ft_i_to_bi(d1.parts.m);
	if ((size = ft_check_excep(d1.parts.e, m_2, d1.parts.sign, lst_fct)) != -1)
	{
		ft_strdel(&m_2);
		return (size);
	}
	res_final = ft_bi_to_dec(m_2, 0, 1, 66 + lst_fct->precision);
	res_final = ft_calc_exposant(d1.f, res_final, d1.parts.e);
	lst_fct->final = ft_print_float(res_final, lst_fct, 0);
	if (d1.parts.sign == 1)
		lst_fct->final = ft_strjoin_fr("-", lst_fct->final, 2);
	lst_fct->final = ft_attribut(d1.f, lst_fct);
	ft_putstr(lst_fct->final);
	ft_strdel(&res_final);
	ft_strdel(&m_2);
	size = ft_strlen(lst_fct->final);
	ft_strdel(&lst_fct->final);
	return (size);
}
