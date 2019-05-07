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

char	*ft_dtoa(long double mantisse)
{
	int		i;
	char	*res;
	int		j;

	i = 0;
	j = 0;
	res = ft_strnew(128);
	j = (int)mantisse;
	while (i != 66)
	{
		if (i == 1)
		{
			res[i] = '.';
			i++;
		}
		res[i] = j + '0';
		mantisse = mantisse - j;
		mantisse = mantisse * 10;
		j = (int)mantisse;
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
	print = ft_strnew(316);
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

int		ft_check_excep(int exposant, char *mantisse, int signe)
{
	if (exposant >= 32767)
	{
		printf("coucou\n");
		if (mantisse[1] == '1')
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

int    ft_conv_f(va_list args,int flags, void(*display)(long long))
{
	long double i;
	t_float		*f;
	float_cast	d1;
	char		*final;
	char		*res_final;

	(void)flags;
	f = (t_float*)malloc(sizeof(t_float));
	(void)(*display);
	i = va_arg(args, double);
	d1.f = i;
	f->signe = d1.parts.sign;
	f->mantisse = ft_calc_i_bi(d1.parts.mantisse);
	printf("f->matisse == %s",f->mantisse);
	f->exposant = d1.parts.exponent - 16383;
	char *mantisse1 = ft_calc_i_bi(d1.parts.mantisse1);
	char *mantisse_final = ft_strjoin(mantisse1, f->mantisse);
	printf("mantisse final == %s\n",mantisse_final);
if (ft_check_excep(d1.parts.exponent, mantisse_final, f->signe))
		return (0);
	//char *matisse_real = ft_calc_i_bi(d2.parts1.mantisse);
	//printf("reel matisse_rel = %s\n",matisse_real);
	printf("matisse final   == %s\n",mantisse_final);
	printf("exposant == %u",f->exposant);
	//double mantisse2 = ft_bi_to_dec(mantisse1);
	res_final = ft_bi_to_dec(mantisse_final);
	//0101001000001101010010101010000100001110000000100010;
	//char *empty = ft_calc_i_bi(d1.parts.empty);
	//double empty2 = ft_bi_to_dec(empty);
	//printf("empty == %u\n",d1.parts.empty);
	//printf("first mantisse == %.64f\n second mantisse == %.64f\n",f->res_mantisse,mantisse2);
	//long double resultat = f->res_mantisse;
	//printf("resultat = %.128Lf\n",resultat);
	//res_final = ft_dtoa(resultat);
	//printf("res_final == %s\n",res_final);
	if (i >= 0 && i < 1)
		final = ft_calc_exposant_neg(res_final, f->exposant * -1, 0);
	else
		final = ft_calc_exposant_pos(res_final, f->exposant);
	ft_print_float(final, 6, f->signe);
	return (0);
}
