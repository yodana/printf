#include "printf.h"
#include <stdio.h>
char    *ft_conv_e(t_conv *lst_fct, char *res, int comma)
{
    char *new;
    int i;
    int j;
    char *str_comma; 

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
   new = ft_float_round(i - 1, new, lst_fct->precision + 1);
   j = 0;
   while (new[j] != '.')
        j++;
    if (j > 1)
    {
        comma++;
        new[1] = '.';
        new[j] = '0';
    }

        str_comma = ft_itoa(comma - 1);
    if (comma < 10)
        str_comma = ft_strjoin_fr("0", str_comma, 2);
    new = ft_strjoin_fr(new, "e+", 1);
    new = ft_strjoin_fr(new, str_comma, 1);
    return (new);
}