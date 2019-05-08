#include "printf.h"
#include <stdio.h>
char    *ft_calc_exposant_neg(char *res, int stop, int hold)
{
	int i;
	int j;

	i = 0;
	printf("stop == %d\n",stop);
	while (stop - 1 > 0)
	{
		while (res[i])
		{
			j = (hold + (res[i] - '0')) / 2;
			if ((res[i] - '0') % 2 == 1)
				hold = 10;
			else
				hold = 0;
			if (j >= 0)
				res[i] = (j % 10 + '0');
			i++;
		}
		if (hold == 10)
			res = ft_strjoin_fr(res, "5", 1);
		hold = 0;
		i = 0;
		stop--;
	}
	return (res);
}

char    *ft_calc_exposant_pos(char *res, int exposant)
{
	int i;
	int j;
	int hold;
	
	i = ft_strlen(res) - 1;
	hold = 0;
	while (exposant >= 0)
	{
		while (i >= 0)
		{
			j = (res[i] - '0') * 2;
			if (j >= 0)
				res[i] = (j % 10 + '0') + hold;
			if (j >= 10)
				hold = 1;
			else if (j >= 0)
				hold = 0;
			if (i == 0 && j >= 10)
				res = ft_strjoin_fr("1",res, 2);
			i--;
		}
		i = ft_strlen(res) - 1;
		hold = 0;
		exposant--;
	}
	return (res);
}