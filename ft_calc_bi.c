/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_bi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 15:02:44 by yodana            #+#    #+#             */
/*   Updated: 2019/05/08 15:02:47 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_i_to_bi(unsigned long long nbr)
{
	char	*bi;
	int		i;

	i = 31;
	if (!(bi = ft_strnew(32)))
		return (NULL);
	while (nbr >= 1)
	{
		bi[i] = (nbr % 2) + '0';
		nbr = nbr / 2;
		i--;
	}
	return (bi);
}

char		*ft_char_add_str(char **res, int k, char *final)
{
	int j;
	int hold;
	int b;
	int i;

	b = 65;
	hold = 0;
	i = 65;
	j = 0;
	while (i >= 0)
	{
		j = (final[b] - '0') + (res[k][i] - '0') + hold;
		if (j >= 10)
			hold = 1;
		else if (j >= 0)
			hold = 0;
		if (b == 1)
			final[b] = '.';
		if (final[b] != '.')
			final[b] = (j % 10 + '0');
		b--;
		i--;
	}
	return (final);
}

char		*ft_char_add_all(char **res)
{
	char	*final;
	int		k;

	k = 0;
	if (!(final = ft_strnew(66)))
		return (NULL);
	final = ft_memset(final, '0', 66);
	while (k != 64)
	{
		final = ft_char_add_str(res, k, final);
		k++;
	}
	return (final);
}

char		*ft_fill_res(char *resultat, int power, char *m, int i)
{
	if (m[i] && m[i] == '1')
	{
		if (!(resultat = ft_dtoa((1 / (double)ft_power(2, power)))))
			return (NULL);
	}
	else
	{
		if (!(resultat = ft_strnew(65)))
			return (NULL);
		resultat = ft_memset(resultat, '0', 66);
	}
	return (resultat);
}

char		*ft_bi_to_dec(char *m, int i, int power)
{
	char	**resultat;
	char	*final;

	if (!(resultat = (char**)malloc(sizeof(char*) * 66)))
		return (NULL);
	while (i < 64)
	{
		if (!(resultat[i] = ft_fill_res(resultat[i], power, m, i)))
		{
			ft_strrdel(resultat);
			return (NULL);
		}
		power++;
		i++;
	}
	resultat[i] = NULL;
	final = ft_char_add_all(resultat);
	ft_strrdel(resultat);
	return (final);
}
