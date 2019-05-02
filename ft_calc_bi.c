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

double     ft_bi_to_dec(char *m)
{
	int i;
	double res;
	double power = 1;
	i = 0;
	res = 0;
	while(m[i])
	{
		res = res + ((m[i] - '0') * (1 / (double)ft_power(2, power)));
		i++;
		power++;
	}
	return (res);
}