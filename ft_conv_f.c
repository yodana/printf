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

char	*ft_dtoa(long double m)
{
	int		i;
	char	*res;
	int		j;

	i = 0;
	j = 0;
	res = ft_strnew(128);
	j = (int)m;
	while (i != 66)
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
			print = ft_strjoin_fr("1", print, 2);
		}
		else
			print[i] = print[i] + 1;
	}
	return (ft_strsub(print, 0, size + 1));
}

void	ft_print_float(char *res, int precision, int sign)
{
	int		i;
	int		stop;
	char	*print;
	int		comma;

	comma = 0;
	stop = 0;
	i = 0;
	print = ft_strnew(1000);
	while (res[i] != '.')
	{
		print[i] = res[i];
		i++;
		comma++;
	}
	while (stop != precision + 2)
	{
		print[i] = res[i];
		stop++;
		i++;
	}
	if (sign == 1)
		ft_putchar('-');
	res = ft_float_round(i - 1, print, comma + precision);
	ft_putstr(res);
}

int		ft_check_excep(int exposant, char *m, int signe)
{
	if (exposant >= 32767)
	{
		if (m[1] == '1')
		{
			ft_putstr("nan");
			return (1);
		}
		if (signe == 1)
			ft_putstr("-inf");
		else
			ft_putstr("inf");
		return (1);
	}
	return (0);
}
#include <stdio.h>
int		ft_conv_f(va_list args, int flags, void (*display)(long long))
{
	float_cast	d1;
	char		*final;
	char		*res_final;
	char		*m_final;

	(void)(*display);
	if (flags == FL)
		d1.f = va_arg(args, long double);
	else
		d1.f = va_arg(args, double);
	m_final = ft_strjoin(ft_i_to_bi(d1.parts.m1), ft_i_to_bi(d1.parts.m));
	if (ft_check_excep(d1.parts.e, m_final, d1.parts.sign))
		return (0);
	res_final = ft_bi_to_dec(m_final);
	printf("res_final == %s\n",res_final);
	if (d1.f < 1 && d1.f > -1)
		final = ft_calc_exposant_neg(res_final, (d1.parts.e - 16383) * -1, 0);
	else
		final = ft_calc_exposant_pos(res_final, d1.parts.e - 16383);
	ft_print_float(final, 6, d1.parts.sign);
	return (0);
}
