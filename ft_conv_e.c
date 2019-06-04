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
    while (i <= lst_fct->precision + 21)
    {
        if (res[j] != '.')
        {
            new[i] = res[j];
            i++;
        }
        j++;
    }
    if (ft_check_float_round(new, lst_fct->precision) == 1)
    new = ft_float_round(i - 21, new,
   lst_fct->precision + 21);
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
    if (lst_fct->precision == 1)
	    new = ft_strsub(new, 0, 1);
    if (lst_fct->precision <= 1  && ft_strrchr(lst_fct->attribut, '#') != NULL)
    new = ft_strjoin_fr(new, ".", 1);
    if (comma < 10)
        str_comma = ft_strjoin_fr("0", str_comma, 2);
    new = ft_strjoin_fr(new, "e+", 1);
    new = ft_strjoin_fr(new, str_comma, 1);
    return (new);
}