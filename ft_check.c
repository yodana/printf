/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:09:12 by yodana            #+#    #+#             */
/*   Updated: 2019/05/27 11:11:08 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_check_precision(int *i, const char *format)
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
#include <stdio.h>
int		ft_check_champ(int *i, const char *format)
{
	int resultat;
	int k;

	k = 0;
	if (format[k] == '-' && (format[k + 1] == '#'))
	{
		resultat = ft_atoi(&format[k + 2]) * -1;
	}
	else if (format[k] == '-' && format[k + 1] == '+')
		resultat = ft_atoi(&format[k + 1]) * -1;
	else
		resultat = ft_atoi(format);
	while (ft_isdigit(format[k]) == 1 || format[k] == '-'
		|| format[k] == '+' || format[k] == '#')
	{
		k++;
		*i = *i + 1;
	}
	return (resultat);
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

char	*ft_check_hp(const char *format, int i, char *res)
{
	if ((format[i + 1] && format[i + 1] == '+')
		|| (format[i + 2] && format[i + 2] == '+'))
	{
		if (!(res = ft_strjoin_fr(res, "+", 1)))
			return (NULL);
	}
	if (format[i + 1] && format[i + 1] == '#')
	{
		if (!(res = ft_strjoin_fr(res, "#", 1)))
			return (NULL);
	}
	/*if (format[i + 1] && format[i + 1] == ' ')
	{
		if (!(res = ft_strjoin_fr(res, " ", 1)))
			return (NULL);
	}*/
	return (res);
}

char	*ft_check_attribut(int *i, const char *format, int k, int j)
{
	char *attributs;
	char *res;

	if (!(res = ft_strnew(10)))
		return (NULL);
	if (!(attributs = ft_fill_attribut()))
		return (NULL);
	while (ft_is_attribut(format[*i]) == 1 && (format[*i] == '0'
			|| ft_isdigit(format[*i]) == 0) && format[*i] != '-'
				&& format[*i] != '.')
	{
		while (attributs[j])
		{
			if (attributs[j] == format[*i])
				res[k++] = attributs[j];
			j++;
		}
		j = 0;
		*i = *i + 1;
	}
	res = ft_check_hp(format, *i, res);
	ft_strdel(&attributs);
	return (res);
}
