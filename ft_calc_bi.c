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
	b = 66;
	i = 66;
	j = 0;
	int k = 0;
	int hold = 0;
	final = ft_strnew(66);
	final = ft_memset(final, '0', 66);
	k = 0;
	printf("final before == %s\n",final);
	while (k != 64)
	{
		while (i >= 0)
		{
			j = (final[b] - '0') + (res[k][i] - '0') + hold;
			if (j >= 10)
				hold = 1;
			else if (j >= 0)
				hold = 0;
			else if (b == 1)
				final[b] = '.';
			if (final[b] != '.')
				final[b] = (j % 10 + '0');
			b--;
			i--;
		}
		b = 66;
		i = 66;
		printf("resultat before == %s || k == %d\n",res[k],k);
		k++;
		//printf("final == %s || j == %d\n",final,j);
	}
	printf("final == %s || j == %d \n",final,j);
	return (final);
}
char *ft_bi_to_dec(char *m)
{
	int i;
	long double res;
	int power = 1;
	char **resultat;
	char *final = NULL;
	resultat = (char**)malloc(sizeof(char*) * 65); 
	i = 0;
	res = 0;
	printf("mantisse == %s\n",m);
	while(m[i])
	{
		resultat[i] = ft_strnew(67);
		if (m[i] == '1')
			resultat[i] = ft_dtoa((1 / (double)ft_power(2, power)));
		else
			resultat[i] = ft_memset(resultat[i], '0', 66);
		i++;
		power++;
	}
	while (i < 64)
	{
		resultat[i] = ft_strnew(67);
		resultat[i] = ft_memset(resultat[i], '0', 66);
		i++;
	}
	printf("i == %d\n",i);
	final = ft_char_add(resultat);
	return (final);
}