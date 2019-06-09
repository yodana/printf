/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:20:58 by yodana            #+#    #+#             */
/*   Updated: 2019/06/09 22:21:26 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
char	*ft_scientific(t_conv *lst_fct, char *res)
{
	char *new;
	int i;
	int j;
	char *str_comma;
	int comma = ft_calc_comma(res);

	j = 1;
	i = 2;
	new = ft_strnew(ft_strlen(res));
	new[0] = res[0];
	new[1] = '.';
	while (i <= lst_fct->precision + 21)
	{
		if (res[j] != '.')
		{
			new[i] = res[j];
			i++;
		}
		j++;
	}
	char *tmp;
	if (ft_check_float_round(new, lst_fct->precision) == 1)
	{
		tmp = ft_float_round(i - 21, new, lst_fct->precision + 1);
		ft_strdel(&new);
		new = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	j = 0;
	while (new[j] != '.')
		j++;
	if (j > 1)
	{
		comma++;
		new[1] = '.';
		new[j] = '0';
	}
	str_comma = ft_itoa(comma - 1);
	if (lst_fct->precision == 1)
		new = ft_strsub_fr(new, 0, 1);
	if (lst_fct->type == 'g')
		new = ft_sup_zero(new, lst_fct->precision);
	if (lst_fct->precision <= 1  && ft_strrchr(lst_fct->attribut, '#') != NULL)
		new = ft_strjoin_fr(new, ".", 1);
	if (comma <= 10)
		str_comma = ft_strjoin_fr("0", str_comma, 2);
	new = ft_strjoin_fr(new, "e+", 1);
	new = ft_strjoin_fr(new, str_comma, 1);

	return (new);
}

int		ft_check_number(char *res)
{
	int i;

	i = 0;
	if (res == NULL)
		return (-1);
	int size = (int)ft_strlen(res);
	while (i <= size && (res[i] == '0' || res[i] == '.'))
		i++;
	if (i == size)
		return (-1);
	return (i);
}

char	*ft_e_zero(t_conv *lst_fct, t_float d1)
{
	int size;
	char		*res_final = NULL;
	char		*m_2;
	int comma;
	char *new;
	int i;
	char *str_comma;
	i = 2;

	size = 66;
	m_2 = ft_i_to_bi(d1.parts.m);
	while ((comma = ft_check_number(res_final)) == -1)
	{
		ft_strdel(&res_final);
		res_final = ft_bi_to_dec(m_2, 0, 1, size + lst_fct->precision);
		res_final = ft_calc_exposant(d1.f, res_final, d1.parts.e);
		size = size * 2;
	}
	ft_strdel(&m_2);
	new = ft_strnew(ft_strlen(res_final));
	new[0] = res_final[comma];
	new[1] = '.';
	while (i <= lst_fct->precision + 21)
	{
		new[i] = res_final[i + comma - 1];
		i++;
	}
	ft_strdel(&res_final);     
	char *tmp;
	if (ft_check_float_round(new, lst_fct->precision) == 1)
	{
		tmp = ft_float_round(i - 21, new, lst_fct->precision + 1);
		ft_strdel(&new);
		new = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	int j = 0;
	while (new[j] != '.')
		j++;
	if (j > 1)
	{
		comma--;
		new[1] = '.';
		new[j] = '0';
	}
	str_comma = ft_itoa(comma - 1);
	if (lst_fct->precision == 1)  
		new = ft_strsub_fr(new, 0, 1);
	if (lst_fct->type == 'g')
		new = ft_sup_zero(new, lst_fct->precision);
	if (lst_fct->precision <= 1  && ft_strrchr(lst_fct->attribut, '#') != NULL)
		new = ft_strjoin_fr(new , ".", 1);
	if (comma <= 10)
		str_comma = ft_strjoin_fr("0", str_comma, 2);
	if (comma - 1 != 0)
		new = ft_strjoin_fr(new, "e-", 1);
	else
		new = ft_strjoin_fr(new, "e+", 1);
	new = ft_strjoin_fr(new, str_comma, 3);
	return (new);
}

int		ft_conv_e(t_conv *lst_fct, va_list args, int flags)
{
	t_float		d1;
	char		*res_final;
	char		*m_2;
	int			size;

	d1.f = flags == FL ? va_arg(args, long double) : va_arg(args, double);
	lst_fct->precision = lst_fct->precision == 0 ? 7 : lst_fct->precision;
	if (d1.f < 1 && d1.f > -1 && d1.f != 0)
		lst_fct->final = ft_e_zero(lst_fct, d1);
	else
	{
		m_2 = ft_i_to_bi(d1.parts.m);
		if ((size = ft_check_excep(d1.parts.e, m_2, d1.parts.sign, lst_fct)) != -1)
		{
			ft_strdel(&m_2);
			return (size);
		}
		res_final = ft_bi_to_dec(m_2, 0, 1, 66 + lst_fct->precision);
		res_final = ft_calc_exposant(d1.f, res_final, d1.parts.e);
		lst_fct->final = ft_print_float(res_final, lst_fct, 0);
		lst_fct->final = ft_scientific(lst_fct, lst_fct->final);
		ft_strdel(&m_2);
		ft_strdel(&res_final);
	}
	if (d1.parts.sign == 1)
		lst_fct->final = ft_strjoin_fr("-", lst_fct->final, 2);
	lst_fct->final = ft_attribut(d1.f, lst_fct);
	ft_putstr(lst_fct->final);
	size = ft_strlen(lst_fct->final);
	ft_strdel(&lst_fct->final);
	return (size);
}
