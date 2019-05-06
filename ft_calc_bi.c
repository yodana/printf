#include "printf.h"

char *ft_calc_i_bi(unsigned long long nbr)
{
	char *bi;
	int i = 0;
	bi = malloc(sizeof(char) * 64 + 1);
	while (nbr >= 1)
	{
		bi[i] = (nbr % 2) + '0';
		nbr = nbr / 2;
		i++;
	}
	bi[i] = '\0';
	bi = ft_strrev_fr(bi);
	return (bi);
}
#include <stdio.h>

char		*ft_char_add(char **res)
{
	int j;
	char *final;
	int i;
	int b;

	b = 64;
	i = 64;
	j = 0;
	int k = 0;
	int hold = 0;
	final = ft_strnew(66);
	while (k != 66)
	{
		final[k] = '0';
		k++;
	}
	k = 0;
	printf("final before == %s\n",final);
	while (k != 64)
	{
		while (i >= 0)
		{
			j = (final[b] - '0') + (res[k][i] - '0');
			if (j >= 10)
				hold = 1;
			else if (j >= 0)
				hold = 0;
			else
				final[b] = '.';
			if (final[b] == '9' && hold == 1)
				final[b] = '0';
			else if (final[b] != '.')
				final[b] = (j % 10 + '0') + hold;
			b--;
			i--;
		}
		b = 64;
		i = 64;
		k++;
		printf("final == %s || j == %d\n",final,j);
	}
	return (final);
}
double     ft_bi_to_dec(char *m)
{
	int i;
	long double res;
	int power = 1;
	char **resultat;

	resultat = (char**)malloc(sizeof(char*) * 65); 
	i = 0;
	res = 0;
	while(m[i])
	{
		resultat[i] = ft_strnew(64);
		res = res + ((m[i] - '0') * (1 / (double)ft_power(2, power)));
		resultat[i] = ft_dtoa((1 / (double)ft_power(2, power)));
		printf("res == %.64f || resultat = %s\n",(1 / (double)ft_power(2, power)), resultat[i]);
		i++;
		power++;
	}
	ft_char_add(resultat);
	return (res);
}