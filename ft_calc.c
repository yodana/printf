/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:13:41 by yodana            #+#    #+#             */
/*   Updated: 2019/05/27 18:15:02 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_calc_octa(long long nbr)
{
	char *res;
	char *c;

	c = ft_strnew(1);
	res = ft_strnew(1);
	if (nbr == 0)
		res = ft_strjoin_fr("0", res, 2);
	while (nbr >= 1)
	{
		c[0] = (nbr % 8) + '0';
		res = ft_strjoin_fr(c, res, 2);
		nbr = nbr / 8;
	}
	ft_strdel(&c);
	return (res);
}

char	*ft_calc_long_hexam(long long nbr)
{
	char *res;
	char *c;

	c = ft_strnew(1);
	res = ft_strnew(0);
	if (nbr == 0)
		res = ft_strjoin_fr("0", res, 2);
	while (nbr >= 1)
	{
		if (nbr % 16 >= 10)
			c[0] = (55 + (nbr % 16));
		else
			c[0] = (nbr % 16) + '0';
		res = ft_strjoin_fr(c, res, 2);
		nbr = nbr / 16;
	}
	ft_strdel(&c);
	return (res);
}

char	*ft_calc_long_hexa(long long nbr)
{
	char *res;
	char *c;

	c = ft_strnew(1);
	res = ft_strnew(0);
	if (nbr == 0)
		res = ft_strjoin_fr("0", res, 2);
	while (nbr >= 1)
	{
		if (nbr % 16 >= 10)
			c[0] = (87 + (nbr % 16));
		else
			c[0] = (nbr % 16) + '0';
		res = ft_strjoin_fr(c, res, 2);
		nbr = nbr / 16;
	}
	ft_strdel(&c);
	return (res);
}

char	*ft_calc_hexa(unsigned long nbr)
{
	char *res;
	char *c;

	c = ft_strnew(1);
	res = ft_strnew(0);
	if (nbr == 0)
		res = ft_strjoin_fr("0", res, 2);
	while (nbr >= 1)
	{
		if (nbr % 16 >= 10)
			c[0] = (87 + (nbr % 16));
		else
			c[0] = (nbr % 16) + '0';
		res = ft_strjoin_fr(c, res, 2);
		nbr = nbr / 16;
	}
	ft_strdel(&c);
	return (res);
}
