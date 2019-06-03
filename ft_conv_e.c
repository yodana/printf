#include "printf.h"
#include <stdio.h>
char    *ft_conv_e(t_conv *lst_fct, char *res, int comma)
{
    char *new;
    int i;
    int j;
    char *str_comma; 

    str_comma = ft_itoa(comma - 1);
    j = 1;
    i = 2;
    new = ft_strnew(ft_strlen(res));
    new[0] = res[0];
    new[1] = '.';
    while (i <= lst_fct->precision + 1)
    {
        if (res[j] != '.')
        {
            new[i] = res[j];
            i++;
        }
        j++;
    }
    if (ft_check_float_round(&new[comma - 1], lst_fct->precision) == 1 && lst_fct->type != 'e')
	{
		new = ft_float_round(i, new, lst_fct->precision);
	}
    if (comma < 10)
        str_comma = ft_strjoin_fr("0", str_comma, 2);
    new = ft_strjoin_fr(new, "e+", 1);
    new = ft_strjoin_fr(new, str_comma, 1);
    return (new);
}